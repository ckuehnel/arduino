#include <SHT31.h>
#include <Arduino.h>
#include <Wire.h>
#include <Console.h>
#include <FileIO.h>

const int ledPin = 13;            // the pin that the LED is attached to
const unsigned int cycle = 60000; // measuring cycle 60 sec

SHT31 sht31 = SHT31();

void setup() 
{
  // initialize serial communication:
  Bridge.begin();
  Console.begin(); 
  sht31.begin();
  FileSystem.begin();

  while (!Console); // wait for Console port to connect.
  Console.println("You're connected to the Console");
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT); 
}

void loop() 
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  float temp = sht31.getTemperature();
  float hum = sht31.getHumidity();
  Console.print("Temp = "); 
  Console.print(temp);
  Console.println(" C"); //The unit for Celsius because original arduino don't support special symbols
  float fTemp = temp * 1.8 + 32;
  Console.print("Temp = "); 
  Console.print(fTemp);
  Console.println(" F"); //The unit for Fahrenheid because original arduino don't support special symbols
  Console.print("Hum  = "); 
  Console.print(hum);
  Console.println(" %"); 
  Console.println();
  File f = FileSystem.open("/tmp/TEMP", FILE_WRITE);
  f.print(temp);
  f.close();
  File ff = FileSystem.open("/tmp/TEMPF", FILE_WRITE);
  ff.print(fTemp);
  ff.close();
  File fff = FileSystem.open("/tmp/HUMI", FILE_WRITE);
  fff.print(hum);
  fff.close();
  digitalWrite(ledPin, LOW);   // sets the LED off
  delay(cycle);
}
