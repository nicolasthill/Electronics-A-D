
const int LED1 =  12;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  pinMode(LED1, OUTPUT);

}

void loop() {
  
  
  digitalWrite(LED1, LOW); //maybe to be commented out or delayed by a short time to avoid the lamp turning off again too fast
  delay(1000);
  digitalWrite(LED1, HIGH);

}
