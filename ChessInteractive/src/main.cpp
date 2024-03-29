#include "Arduino.h"
#include <WifiHandler.h>
  #include <WiFi.h>               // connecting to router
// #include <AsyncHandler.h>
  #include <HTTPClient.h>         // http requests
  #include <ESPAsyncWebServer.h>  // used for websockets
  #include <AsyncTCP.h>           // used for websockets:
  #include <ArduinoJson.h> 
#include <SPIFFSHandler.h>
  #include <SPIFFS.h>             // For flash memory of the html, css, javascript files
#include <LichessAPI.h>         // Jacobs api class for lichess
#include <PhysicalBoard.h>
#include <NeoPixel.h>

// #include "ChessGame.h"
// ChessGame* myGame = new ChessGame();

// https://randomnerdtutorials.com/esp32-websocket-server-arduino/
// https://techtutorialsx.com/2021/12/06/esp32-websocket-server-broadcast-messages/#Introduction
// https://www.youtube.com/watch?v=mkXsmCgvy0k&t=291s
// https://www.youtube.com/watch?v=tDdL5urWvH4
// https://www.youtube.com/watch?v=_bar1Nhfj-Y&t=212s
// https://circuits4you.com/2018/11/20/web-server-on-esp32-how-to-update-and-display-sensor-values/
// https://microcontrollerslab.com/esp32-asynchronous-web-server-espasyncwebserver-library/
// https://github.com/me-no-dev/ESPAsyncWebServer

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
unsigned long timerDelay = 5000; // 5 seconds

//gpio output (delete later)
bool ledState = 0;
const int ledPin = 2;

AsyncWebServer server(80); // setup server
AsyncWebSocket ws("/ws"); // setup websockets

void notifyClients() { // send to all clients
  ws.textAll(String(ledState));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) { // handle recieved data from client
  Serial.println("inside handlewebsocketmessage");
  Serial.print("raw data: ");
  Serial.println((char*)data);

  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;

    if (strcmp((char*)data, "toggle") == 0) { // delete later
      Serial.println("inside if for toggle");
      ledState = !ledState;
      notifyClients();
      return;
    }
    Serial.println((char*)data);

    String dataRecieved = (char*)data;
    DynamicJsonDocument doc(3000);
    deserializeJson(doc, dataRecieved);


    if(doc.containsKey("firstName")){
      Serial.println("inside if for firstname");
        const char* test = doc["firstName"];
        Serial.println(test);
    }
    if(doc.containsKey("chessMoveTxt")){
      const char* test = doc["chessMoveTxt"];
      // LichessAPI::makeABotMove(LichessAPI::getCurrentGameId(), test); // if using bot
      LichessAPI::makeABoardMove(LichessAPI::getCurrentGameId(), test); // if using user
    }
  }
}

// handles events whether error 404 or successful 200
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

// on webpage load
void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

String processor(const String& var){ // replaces the temporary placeholders with values, ex: %username% 
  Serial.println(var);
  if(var == "STATE"){
    if (ledState){
      return "ON";
    }
    else{
      return "OFF";
    }
  }
  if(var == "USERNAME"){
    return "username";
  }

  return String();
}

void setup() {
  Serial.begin(115200); // serial monitor

  // delete later
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // WIFI stuff
  WifiHandler::setSSID("CenturyLink4841");
  WifiHandler::setPassword("36e3b7u8eawa3y");
  WifiHandler::beginWifi();

  // Physical Board stuff
  PhysicalBoard::setupMCP();

  // LED Board stuff
  NeoPixel::begin();
  NeoPixel::initalizeBoardLED();
  NeoPixel::setBrightness(50);

 // Route for documents / web pages
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String());
    Serial.println("Sent HTML");
  });

  //Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
    Serial.println("Sent CSS");
  });

  // Route to load main.js
  server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/main.js", "text/plain");
    Serial.println("Sent JavaScript");
  });

  initWebSocket();

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.htm", String(), false, processor);
  });

  // Start server
  server.begin();

  // LichessAPI::setLichessToken("lip_kv7qP8TCWBiEaLof4KOf"); // setting lichessAPI harryBotter123
  LichessAPI::setLichessToken("lip_pF1PZ66cS6xkQuqThTg4"); // setting lichessAPI kabooterz
  LichessAPI::setCurrentGameId(LichessAPI::findCurrentGameId()); // lichess bot

}


void loop() {
  // // myBoard->CleartheBoard();

  // digitalWrite(ledPin, ledState);
  // ws.cleanupClients();
  // if ((millis() - lastTime) > timerDelay) { // intervals 
  //   DynamicJsonDocument doc(3000);
  //   doc["setUsername"] = LichessAPI::getMyId();
  //   doc["setFEN"] = LichessAPI::getCurrentGameFEN();
  //   String output;
  //   serializeJson(doc, output);
  //   ws.textAll(output);
  //   lastTime = millis();
  // }
  if (((millis() - lastTime) > timerDelay)  && !PhysicalBoard::isPickedUp && !LichessAPI::isMyTurn) { // no need to check lichess if i have a piece picked up, or its my turn 
    Serial.println("inside main");
    NeoPixel::highlightLastMove();
  }  

  PhysicalBoard::readBoard();
}
