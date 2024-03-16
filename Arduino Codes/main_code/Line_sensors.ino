// This code is for line following QTR sensor panel

#include <QTRSensors.h>

int line_error = 0;

#define line_even 34
#define line_odd 36

#define line_threshold 2400

QTRSensors line_sensor;

const uint8_t SensorCount = 16;
uint16_t sensorValues[SensorCount];
bool ir[SensorCount];



void line_sensor_setup(){
  // configure the sensors
  line_sensor.setTypeRC();
  line_sensor.setSensorPins((const uint8_t[]){53, 51, 49, 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23}, SensorCount);
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

  for (uint8_t i = 0; i < SensorCount; i++){
    ir[i] = sensorValues[i] < line_threshold;
  }

  if(ir[0] == 1 && ir[1] == 1 && ir[2] == 1 && ir[3] == 1 && ir[4] == 1 && ir[5] == 1 && ir[6] == 1 && ir[7] == 1 && ir[8] == 1 && /*ir[9] == 0 && ir[10] == 0 && ir[11] == 0 &&*/ ir[12] == 0 && ir[13] == 0 && ir[14] == 0 && ir[15] == 0){
    return 5002;
  }
  else if(ir[0] == 0 && ir[1] == 0 && ir[2] == 0 && ir[3] == 0 && ir[4] == 0 &&/* ir[5] == 0 && ir[6] == 0 && ir[7] == 0 &&*/ ir[8] == 1 && ir[9] == 1 && ir[10] == 1 && ir[11] == 1 && ir[12] == 1 && ir[13] == 1 && ir[14] == 1 && ir[15] == 1){
    return 5001;
  }

  else if(ir[0] == 1 && ir[1] == 1 && ir[2] == 1 && ir[3] == 1 && ir[4] == 1 && ir[5] == 1 && ir[6] == 1 && ir[7] == 1 && ir[8] == 1 && ir[9] == 1 && ir[10] == 1 && ir[11] == 1 && ir[12] == 1 && ir[13] == 1 && ir[14] == 1 && ir[15] == 1){
    return 5003;
  }

  else if(ir[0] == 0 &&/* ir[1] == 1 && ir[2] == 1 &&*/ ir[3] == 1 && ir[4] == 1 && ir[5] == 1 && ir[6] == 1 && ir[7] == 1 && ir[8] == 1 && ir[9] == 1 && ir[10] == 1 && ir[11] == 1 && ir[12] == 1/* && ir[13] == 0 && ir[14] == 0*/ && ir[15] == 0){
    return 5004;
  }

  else{
    for (uint8_t i = 0; i < SensorCount; i++)
    {
      bool temp_val = ir[i];


      
      Serial.print(temp_val);
      Serial.print("  ");
      int temp = 0;

      if(i <= 7){
        temp = (i-(SensorCount/2));
      }
      else{
        temp = (i-(SensorCount/2)+1);
      }
      
      if(temp == 1) multiplyer = 3;
      else if(temp == 2) multiplyer = 6;
      else if(temp == 3) multiplyer = 10;
      else if(temp == 4) multiplyer = 20;
      else if(temp == 5) multiplyer = 30;
      else if(temp == 6) multiplyer = 40;
      else if(temp == 7) multiplyer = 60;
      else if(temp == 8) multiplyer = 100;
      else if(temp == -1) multiplyer = -3;
      else if(temp == -2) multiplyer = -6;
      else if(temp == -3) multiplyer = -10;
      else if(temp == -4) multiplyer = -12;
      else if(temp == -5) multiplyer = -30;
      else if(temp == -6) multiplyer = -40;
      else if(temp == -7) multiplyer = -60;
      else if(temp == -8) multiplyer = -100;
      
  

      //Serial.print(temp_val*multiplyer);
      //Serial.print("  ");
      line_error += temp_val*multiplyer;
    }


    if(line_error>999)
      line_error = 999;
    if(line_error < -999)
      line_error = -999;

    return line_error;
  }
}

