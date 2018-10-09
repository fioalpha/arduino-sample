/**
 * This code to controller has flow water
 * Using flow sensor and update data between 10 minutes
 * Connected in internet 
 */

#include <ESP8266WiFi.h>

#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD" 

const byte ledPin = LED_BUILTIN;
const byte interruptPin = 14;
long previousMillis = 0;
volatile unsigned long timeCount = 0;
const long interval = 600000; //Await 10 minutes

/**
 * Connected in WIFI
 */
void initWiFi() {
   WiFi.begin( WIFI_SSID,  WIFI_PASSWORD);
   while(WiFi.status() != WL_CONNECTED) {
      digitalWrite(ledPin,  HIGH);
      delay(500);
      digitalWrite(ledPin,  LOW);
      delay(500);
   }
   Serial.println();
   digitalWrite(ledPin,  LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin),setIncrementInTimeCount, RISING);
  initWiFi();
}

void setIncrementInTimeCount() {
 timeCount = timeCount + 1;
}

void loop() {
  if(isTimeFinish()) {
    Serial.println("Count Cicle");
    Serial.println(timeCount);
    timeCount= 0;
  }
}


/**
 * Method verify if finished 
 * return boolean true when finished time or false when finished
 */
boolean isTimeFinish() {
   unsigned long currentMillis = millis();  
   if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    return true;
   }
   return false;
}
