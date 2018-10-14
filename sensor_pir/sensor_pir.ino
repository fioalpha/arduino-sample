
/**
 * This sample show how use sensor de PIR,
 * 
 */
#define PIR_SENSOR_INPUT 2
#define LED_OUTPUT 3

void setup() {
  pinMode(PIR_SENSOR_INPUT, INPUT_PULLUP);
  pinMode(LED_OUTPUT, OUTPUT);
}

void loop() {
  int valueSensor = digitalRead(PIR_SENSOR_INPUT);
  digitalWrite(LED_OUTPUT, valueSensor);
  delay(100);
}
