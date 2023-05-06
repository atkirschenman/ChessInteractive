#include <Arduino.h>

#include "SmartConnect.h"

    void SmartConfig::WifiConnect()
    {
        prefs.begin("credentials"); // use "schedule" namespace
        //Serial.print("Device Mode: "); //Serial.println(deviceMode);
        size_t listLength = prefs.getBytesLength("credentials");
        char buffer[listLength]; // prepare a buffer for the data
        
        prefs.getBytes("credentials", buffer, listLength);
        if (digitalRead(13)) //force to webpage
        {
            if (listLength % sizeof(wificred_t))
            { // simple check that data fits
            log_e("Data is not correct size!");
            return;
            }
            else
            {
            uint8_t networkNum = listLength / sizeof(wificred_t);
            wificred_t *creds = (wificred_t *) buffer; // cast the bytes into a struct ptr
            int n = WiFi.scanNetworks();
            for (int i =0; i<n; i++)//cycle networks found
            {
                for(int j = 0; j<networkNum; j++) //cycle network credentials saved
                {
                Serial.print(WiFi.SSID(i)); Serial.print("  "); Serial.print(creds[j].ssid); Serial.print("  "); Serial.print(WiFi.encryptionType(i)); Serial.print(" ");Serial.println(creds[j].type);
                if(strcmp(WiFi.SSID(i).c_str(),creds[j].ssid)==0 && WiFi.encryptionType(i)==creds[j].type) //check if credentials match
                {
                    if (creds[j].type ==5) //Enterprise///////////////////////////////////////////////////////////////////////////////////////////
                    {
                    const char * EAP_IDENTITY = creds[j].id;
                    const char * EAP_PASSWORD = creds[j].password;

                    WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
                    WiFi.mode(WIFI_STA); //init wifi mode
                    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
                    esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
                    esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
                    //esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //set config settings to default
                    esp_wifi_sta_wpa2_ent_enable();//&config); //set config settings to enable function1ABCDEF
                    WiFi.begin(creds[j].ssid); //connect to wifi
                    uint8_t count=0;
                    while (WiFi.status() != WL_CONNECTED) 
                    {
                        delay(500);
                        count++;
                        Serial.print(".");
                        if (count>100) break;
                    }
                    }
                    else if (creds[j].type ==3) //WPA2/////////////////////////////////////////////////////////////////////////////////////////////
                    {
                    WiFi.begin(creds[j].ssid, creds[j].password);

                    // attempt to connect to Wifi network:
                    while (WiFi.status() != WL_CONNECTED) 
                    {
                        Serial.print(".");
                        // wait 1 second for re-trying
                        delay(1000);
                    }
                    }          
                }
                
                if(WiFi.status() == WL_CONNECTED) break;
                }
                if(WiFi.status() == WL_CONNECTED) break;
            }
            }
        }
        if (WiFi.status()!= WL_CONNECTED)//Go into setup mode
        {
            WiFi.disconnect(true);  //disconnect form wifi to set new wifi connection
            WiFi.mode(WIFI_AP); //init wifi mode
            WiFi.softAP("Chess Setup");
            WiFi.softAPConfig(IP, IP, NMask);
            server.on("/", handleRoot);
            server.on("/network", handleSubmit);
            server.on("/SSIDread",handleSSID);
            server.begin(); //Start server
            
            Serial.println("HTTP server started");
            vTaskDelay(1000/portTICK_RATE_MS);
            bool complete=0;
            while (complete==0)
            {
            server.handleClient();
            }
        }
        else
        {
            WiFi.setSleep(false);
            Serial.println("");
            Serial.println("WiFi connected");
            Serial.println("IP address: ");
            Serial.println(WiFi.localIP());
        }
    }

    void SmartConfig::SubmitCreds()
    {
        if (server.hasArg("SSID") && server.hasArg("PSSWORD")) 
        {
            strcpy(handle.ssid, server.arg("SSID").c_str());
            strcpy(handle.password, server.arg("PSSWORD").c_str());
            strcpy(handle.id, server.arg("ID").c_str());
            handle.type =  server.arg("TYPE").toInt();
            //handle.type = 5;
            prefs.putBytes("credentials", &handle, sizeof(handle));
        }
        server.send(200, "text/plane","");
        ESP.restart();
    }