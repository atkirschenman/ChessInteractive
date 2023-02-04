#include "WifiHandler.h"

const char* WifiHandler::ssid;
const char* WifiHandler::password;

void WifiHandler::setSSID(const char* ssid){
    WifiHandler::ssid = ssid;
}

void WifiHandler::setPassword(const char* password){
    WifiHandler::password = password;
}

const char* WifiHandler::getSSID(){
    return WifiHandler::ssid;
}

const char* WifiHandler::getPassword(){
    return WifiHandler::password;
}

void WifiHandler::beginWifi(){
    WiFi.begin(WifiHandler::getSSID(), WifiHandler::getPassword());
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) { // while not connected, place dots.
        delay(500);
        Serial.print(".");
    }
    Serial.println(WiFi.localIP());
    Serial.println("");
    Serial.println("Connected to WiFi network with IP Address: " + WiFi.localIP()); // connection successful
}
