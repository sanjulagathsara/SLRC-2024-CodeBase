#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define colorSensorLED 52
#define commonAnode true

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void color_sensor_setup(){
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    error_blink(5);
  }

  // use these three pins to drive an LED
  pinMode(colorSensorLED, OUTPUT);
  
}

int getFrontRed(){
  float red, green, blue;
  
  digitalWrite(colorSensorLED,HIGH);
  
  delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");
  digitalWrite(colorSensorLED,LOW);
  return int(red);

  

}

int getFrontBlue(){
  float red, green, blue;
  
  digitalWrite(colorSensorLED,HIGH);
  
  delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");
  digitalWrite(colorSensorLED,LOW);
  return int(blue);

  

}

int getFrontGreen(){
  float red, green, blue;
  
  digitalWrite(colorSensorLED,HIGH);
  
  delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.print("\n");

  digitalWrite(colorSensorLED,LOW);
  return int(green);

  

}