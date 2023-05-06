#ifndef SC_H
#define SC_H
#include "esp_wpa2.h" //wpa2 library for connections to Enterprise networks
#include <Preferences.h>
#include <WiFiClientSecure.h>

class SmartConfig
{
 public:
    void SmartConfig::WifiConnect();
    void SmartConfig::SubmitCreds();
    Preferences prefs;
    typedef struct {
    char ssid[32];
    char password[32];
    char id[32];
    uint8_t type;
    } wificred_t;
    wificred_t handle;
};
#endif

