void connectToMqtt(){
  Serial.println("Conectando para o MQTT");
  mqttClient.connect();
}

void onMqttConnect(bool sessionPresent){
  Serial.println("Conectado no MQTT...");
  mqttClient.subscribe(MQTT_SUB_VALUE_LUZ, 2);
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  Serial.println("Disconectado no MQTT...");

  if(WiFi.isConnected()){
    mqttReconnectTimer.once(2, connectToMqtt);
  }
  
}


void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total){
//  Serial.print(topic);
//  Serial.print(" ---- ");
//  Serial.println(payload[0]);

    if(payload[0] == '1'){
      // Ligo a lampada
      digitalWrite(Rele_1, HIGH);
      mqttClient.publish(MQTT_PUB_STATE_LUZ, 1, true, "1");
      
    }else if(payload[0] == '0'){
      // Desligo a lampada
      digitalWrite(Rele_1, LOW);
      mqttClient.publish(MQTT_PUB_STATE_LUZ, 1, true, "0");
    }
}

void mqttInit(){
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCredentials(USER_MQTT, PASSWORD_MQTT);
  mqttClient.setClientId(ID_MQTT);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onMessage(onMqttMessage);
}
