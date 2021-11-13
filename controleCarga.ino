#include <ESP8266WiFi.h>
#include <AsyncMqttClient.h>
#include <Ticker.h>


#define WIFI_SSID           "AGUIAR_ADM"
#define WIFI_PASSWORD       "a0b9c8d7e6"

#define MQTT_HOST           "mqtt.autodomo.io"
#define MQTT_PORT           1883

const char* USER_MQTT       = "User000001075";
const char* PASSWORD_MQTT   = "upfkk9ym";
#define ID_MQTT             "01AA02762883"

#define MQTT_PUB_STATE_LUZ  "/autodomo/User000001075/01AA02762883/light/state"
#define MQTT_SUB_VALUE_LUZ  "/autodomo/User000001075/01AA02762883/light/value"



AsyncMqttClient mqttClient;
Ticker wifiReconnectTimer;
Ticker mqttReconnectTimer;


WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;

unsigned long tempoAnterior = 0;
const long    intervalo     = 10000;

int Rele_1 = 5; 

void setup() {
  // put your setup code here, to run once:
  initParametros();
  wifiInit();
  connectToWifi();
  mqttInit();

}

void loop() {
  // put your main code here, to run repeatedly:
   unsigned long tempoAtualMillis = millis();

  if(tempoAtualMillis - tempoAnterior >= intervalo){
    tempoAnterior = tempoAtualMillis;
    

    
  }

}
