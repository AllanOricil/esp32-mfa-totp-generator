#include <WiFi.h>

#ifndef WIFI_SSID
#define WIFI_SSID (char*)"CHOCOLATE"
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD (char*)"CHOCOLATE"
#endif

void init_wifi(){
  if(WIFI_SSID == NULL || WIFI_PASSWORD == NULL){
    Serial.printf("Failed to get WiFi details from environment variables");
    return; // Or handle error appropriately
  }

  Serial.printf("Connecting to %s", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());
}
