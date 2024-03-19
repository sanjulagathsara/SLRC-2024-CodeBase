#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define redpin 52
#define commonAnode true


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  }
  pinMode(redpin, OUTPUT);
  
}

void loop() {
  float red, green, blue;
  
  digitalWrite(redpin,HIGH);
  
  delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");

}