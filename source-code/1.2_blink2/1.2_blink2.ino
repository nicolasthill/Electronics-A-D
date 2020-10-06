/*
Expected Bliking Pattern: (one number counts for 500 ms)
LED1:00000000001111111111000000000011111111110
LED2:01010000001010111111010100000010101111110
 */
const int LED1 =  12;
const int LED2 = 8;

int State1 = LOW; 
int State2 = LOW;

unsigned long time1_before = 0;
unsigned long time2_before = 0;

const int long_time = 5000;
const int medium_time = 2500;
const int short_time = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {
  unsigned long time_now = millis();
 
  //LED2 blinks with a frequency of 10 Hz for 
  if (time_now - time1_before < medium_time) {
    if (time_now - time2_before >= short_time){
      time2_before = time_now;
      if (State2 == LOW) {
      State2 = HIGH;
      } else {
      State2 = LOW;
      }
    }
  }
  
  //LED1 blinks with a frequency of 1 Hz
  if (time_now - time1_before >= long_time) {
    time1_before = time_now;
    if (State1 == LOW) {
      State1 = HIGH;
    } else {
      State1 = LOW;
    }
  }
  
  digitalWrite(LED1, State1);
  digitalWrite(LED2, State2);
}
