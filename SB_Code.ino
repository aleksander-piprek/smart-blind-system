#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include "webpageCode.h";

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

const char* AP_SSID="Smart Blinds";
const char* AP_Password="maslo123";

const int stepPin = 14; 
const int dirPin = 12; 

int i = 0;

#include "functions.h"

void setup() {
  Serial.begin(115200);
  WiFi.disconnect(true);
  WiFi.mode(WIFI_AP);
  // local_ip,   gateway,   subnet
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(AP_SSID,AP_Password);
  dnsServer.start(DNS_PORT, "*", apIP);
  Serial.print(apIP);
  webServer.onNotFound([]() {
  webServer.on("/", webPage);
  webServer.on("/clk", Clockwise);  
  webServer.on("/cclk", CounterClockwise); 
  ;});
  webServer.begin();
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
