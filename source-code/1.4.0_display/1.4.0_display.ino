#include <Wire.h>
#include "rgb_lcd.h"
 
rgb_lcd lcd;

int ON = 255;
int OFF = 0;
int colorR = OFF;
int colorG = OFF;
int colorB = OFF;


const int B = 4275;               // Nominal B-constant
const int R0 = 100000;            // Zero power resitance in kOhm

const int pinThermo = A0;
const int pinRotary = A1;

const int ADC_REF = 5;
const int GROVE_VCC = 5;
const int FULL_ANGLE = 300;

const int measurement_interval = 1000;
unsigned long time_before = 0;

const float base_threshold = 0.16; // 48/300 such that max threshold is 48 degrees
float threshold = base_threshold;

 
void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
 
    lcd.setRGB(colorR, colorG, colorB);
 
    // Print a message to the LCD.
    lcd.print("Temperature is");

    pinMode(pinRotary, INPUT);
 
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
}
 
void loop() 
{
  unsigned long time_now = millis();
  if (time_now - time_before >= measurement_interval) {
    time_before = time_now;

    // rotary sensing
    float voltage;
    int sensor_value = analogRead(pinRotary);
    voltage = (float)sensor_value*ADC_REF/1023;
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;
    Serial.println("The angle between the mark and the starting position:");
    Serial.println(degrees);
    
    int a = analogRead(pinThermo);
 
    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature

    threshold = base_threshold * degrees;
    
    if (temperature > threshold) {
      colorR = ON;
      colorG = OFF;
      lcd.setRGB(colorR, colorG, colorB);
    } else {
      colorR = OFF;
      colorG = ON;
      lcd.setRGB(colorR, colorG, colorB);
    }
    lcd.setCursor(0, 1);
    lcd.print(temperature);
 
    delay(100);
  }
}
