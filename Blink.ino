/*
 Blink
 Turns on an LED on for short time, then off for two seconds, repeatedly.
 This example code is in the public domain.
 */
 #include <Bridge.h>

// Pin 13 has an LED connected on most Arduino boards.
const int led = 13;

// the setup routine runs once when you press reset:
void setup() { 
  Bridge.begin();               
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  // initialize serial port 
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(20);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);            // wait for a second
  Serial.write("*");
}

