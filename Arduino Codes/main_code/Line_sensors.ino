// This code is for line following QTR sensor panel

#include <QTRSensors.h>

int line_error = 0;

#define line_even 34
#define line_odd 36

#define line_threshold 2400

QTRSensors line_sensor;

const uint8_t SensorCount = 16;
uint16_t sensorValues[SensorCount];


void line_sensor_setup(){
  // configure the sensors
  line_sensor.setTypeRC();
  line_sensor.setSensorPins((const uint8_t[]){23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53}, SensorCount);
  line_sensor.setEmitterPin(2);

  pinMode(line_even,OUTPUT);
  pinMode(line_odd,OUTPUT);
  digitalWrite(line_even,HIGH);
  digitalWrite(line_odd,HIGH);
}


int cal_line_error(){
// read raw sensor values
  line_sensor.read(sensorValues);

  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  line_error = 0;
  int multiplyer = 0;
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    bool temp_val = sensorValues[i] < line_threshold;


    
    Serial.print(temp_val);
    Serial.print("  ");
    
    
    


    if(i <= 7){
      multiplyer = pow((i-(SensorCount/2)),3);
    }
    else{
      multiplyer = pow((i-(SensorCount/2)+1),3);
    }
     //Serial.print(temp_val*multiplyer);
    //Serial.print("  ");
    line_error += temp_val*multiplyer;
  }


  if(line_error>1000)
    line_error = 1000;
  if(line_error < -1000)
    line_error = -1000;

  return line_error;
}

