#include "AsyncHandler.h"

AsyncWebServer server(80); // setup server
AsyncWebSocket ws("/ws"); // setup websockets
int AsyncHandler::led;

void AsyncHandler::setLedState(int ledState){
    AsyncHandler::led = ledState;
}

int AsyncHandler::getLedState(){
    return AsyncHandler::led;
}

AsyncWebServer getServer(){
    return server;
}

AsyncWebSocket getWebsocket(){
    return ws;
}

void notifyClients() { // send to all clients
  ws.textAll(String(AsyncHandler::getLedState()));
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
      AsyncHandler::setLedState(!AsyncHandler::getLedState());
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
      LichessAPI::makeABotMove(LichessAPI::getCurrentGameId(), test);
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
    if (AsyncHandler::getLedState()){
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