
const int B = 4275;               // Nominal B-constant
const int R0 = 100000;            // Zero power resitance in kOhm

const int pinThermo = A0;
const int measurement_interval = 1000;

unsigned long time_before = 0;

void setup() {
  Serial.begin(9600);
  
  
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  unsigned long time_now = millis();
  if (time_now - time_before >= measurement_interval) {
    time_before = time_now;
    
    int a = analogRead(pinThermo);
 
    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
 
    Serial.print("temperature = ");
    Serial.println(temperature);
    Serial.print(" at time: ");
    Serial.println(time_now);
 
  }
}
