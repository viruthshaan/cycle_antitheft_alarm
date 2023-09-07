#include <avr/sleep.h>

const int vibrationPin = 9; // vibration sensor connected to digital pin 9
const int speaker = 13; // Speaker connected to digital pin 13
const int led = 12; // LED connected to digital pin 13

int threshold = 0; // vibration threshold value
int count = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(vibrationPin, INPUT); // set vibration pin as input
  pinMode(speaker, OUTPUT); // set speaker pin as output
  Serial.begin(9600); // initialize serial communication for debugging
}

void loop() {

  digitalWrite(led, HIGH); // turn on LED
  
  long vibrationValue = vibration();
  delay(50);
  Serial.println(vibrationValue); // print sensor value for debugging

  if (vibrationValue > threshold) { // if vibration is above threshold
    digitalWrite(speaker, HIGH); // turn on speaker
    delay(10000);
  } 
  
  digitalWrite(speaker, LOW); // turn off speaker



  
}

long vibration() {
  long vibrationValue = pulseIn(vibrationPin, HIGH);
   
  return vibrationValue;
}
