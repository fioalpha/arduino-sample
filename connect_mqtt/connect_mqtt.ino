
#include<ESP8266WiFi.h>
#include<PubSubClient.h>

#define WIFI_SSID "NEED CHANGE TO YOUR SSID NETWORK"
#define WIFI_PASSWORD "NEED CHANGE TO YOUR PASSWORD" 
#define BROKER_MQTT_IP "ADD IP OF MQTT SERVER"
#define BROKER_MQTT_PORT 0 //NEED PORT MQTT SERVER

WiFiClient espClient; //Client to wifi
PubSubClient MQTT(espClient); //Client MQTT broken

/**
 * Method that conntected MQTT server
 * Need create callback to receiver response server and make handler response 
 */
void initMQTT() {
  MQTT.setServer(BROKER_MQTT_IP, BROKER_MQTT_PORT);  
  MQTT.setCallback(messageMqttServerCallback);
}

/**
 * Method callback response server mqtt 
 * handle message of mqtt server
 */
void messageMqttServerCallback(char* topic, byte* payload, unsigned int length) {
    String message;
    for(int i = 0; i< length; i++) {
      char character = (char) payload[i];
      message += character;  
    }
    log(message);
    log(topic);
} 

/**
 * Method conected wifi 
 * This conected WIFI
 */
void conectedWIFI() {
  long("Init setup WIFI ... ");

  while(WiFi.status() != WL_CONNECTED) {
    delay(100);  
    Serial.print(".");
  }
  Serial.println();
  log("You connected in network "+String(WIFI_SSID) + " | IP => "+String(WiFi.localIP())); 
}

/**
 * Method conneting MQTT SERVER
 */

void connectInMqttServer() {
  while(!MQTT.connected()) {
    log("try connect in MQTT server");
    
    if(MQTT.connect("")) {
      log("Connected in MQTT server");
      MQTT.subscribe("test"); //Subscribe in topic
      MQTT.subscribe("test/#"); //subscribe topic and your child
      MQTT.publish("test","Helloworld"); //publish message on topic
    } else {
      log("Has error to connected");
      log("Try again in 2 second");
      delay(2000);
    }
      
  }  
}

/**
 * Method show log in serial console
 */
void log(String message) {
  Serial.println(message);
}

void setup() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.begin(115200);
//  initPin();
  conectedWIFI();
  initMQTT();
}

void loop() {
  connectInMqttServer();
  MQTT.loop();
}
