#ifndef AsyncHandler_h
#define AsyncHandler_h
    #include <ESPAsyncWebServer.h>  // used for websockets
    #include <AsyncTCP.h>           // used for websockets:
    #include <ArduinoJson.h> 
    #include <LichessAPI.h>         // Jacobs api class for lichess
    
    class AsyncHandler{
        private: 
            static AsyncWebServer server(int number); // setup server
            static AsyncWebSocket ws(const char* websocket); // setup websockets
            static void notifyClients();// send to all clients
            static void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
            static int led;
        public:
            static void setLedState(int ledState);
            static int getLedState();
            static void setupServer();
            static void setupWebsockets();
            static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
            static void initWebSocket();
            static String processor(const String& var);
            static void beginServer();  
            static AsyncWebServer getServer(); // setup server
            static AsyncWebSocket getWebsocket();

    };

#endif