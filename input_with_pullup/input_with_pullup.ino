
const byte INPUT_PIN = 2;
int val = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT_PULLUP);
}

void loop() {
  val = digitalRead(INPUT_PIN);
  digitalWrite(LED_BUILTIN, !val);
}
