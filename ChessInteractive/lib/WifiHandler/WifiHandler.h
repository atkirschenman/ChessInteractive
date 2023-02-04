#ifndef WifiHandler_h
#define WifiHandler_h
    #include <WiFi.h>               // connecting to router
    #include <HTTPClient.h>         // http requests

    class WifiHandler{
        private: 
            static const char* ssid;
            static const char* password;

        public:
            static void setSSID(const char* ssid);
            static void setPassword(const char* password);
            static const char* getSSID();
            static const char* getPassword();
            static void beginWifi();
    };

#endif
