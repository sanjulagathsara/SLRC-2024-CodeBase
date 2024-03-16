// File:          slrc24_controller.cpp
// Date:
// Description:
// Author: Team RoboticGen
// Modifications:

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/LED.hpp>
#include <webots/Camera.hpp>

#include <iostream>

using namespace webots;
using namespace std;

DistanceSensor *lineSensor[8];
double lineSensorVal[8];


bool lineV[8];
float pVal;
float Kp = 5;
float baseSpeed = 5;
bool TJuncFlag = 0;
  
int junction = 0;
int error = 0;

void ReadGsensors() { //function for read Ground sensors
  for (int i = 0; i < 8; i++) { 
  //AGval[i] = lineSensor[i]->getValue();
    //std::cout<<"sensor"<<i<<"    "<<AGval[i]<< std::endl;
  //DGval[i] = 1 - ((AGval[i] - 39) / (116 - 39));
 // std::cout<<"sensor"<<i<<"    "<<DGval[i]<< std::endl;
  lineSensorVal[i] = lineSensor[i]->getValue();
  }
}

int main(int argc, char **argv) {

  // create the Robot instance.
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  

  Motor *left_motor = robot->getMotor("left_motor");
  Motor *right_motor = robot->getMotor("right_motor");

  char lineSensorNames[8][32] = {"lineSensor0", "lineSensor1", "lineSensor2", "lineSensor3", "lineSensor4", "lineSensor5", "lineSensor6", "lineSensor7"};
  
  for (int i = 0; i < 8; i++) {
    //std::cout << lineSensorNames[i] << std::endl;

    lineSensor[i] = robot->getDistanceSensor(lineSensorNames[i]);
    lineSensor[i]->enable(timeStep);

  }
  
  Camera *front_color_sensor = robot->getCamera("front_color_sensor");
  
  LED *stoneHolderLED = robot->getLED("stoneHolderLED");

  
  left_motor->setPosition(INFINITY);
  right_motor->setPosition(INFINITY);
  
  left_motor->setVelocity(-baseSpeed);
  right_motor->setVelocity(-baseSpeed);

  front_color_sensor->enable(timeStep);
  
  stoneHolderLED->set(1);
  
  
  

  std::cout << "Robot is Starting!" << std::endl;

  // Main loop:

  while (robot->step(timeStep) != -1) {
    
    ReadGsensors();
    
    //cout<<lineSensor[0]<<" "<<lineSensor[1]<<" "<<lineSensor[2]<<" "<<lineSensor[3]<<" "<<lineSensor[4]<<" "<<lineSensor[5]<<" "<<lineSensor[6]<<" "<<lineSensor[7]<<endl;
    
    
    for(int i=0;i<8;i++){
      if(lineSensorVal[i] < 500.00){
        lineV[i] = 1;
      }
      else{
        lineV[i] = 0;
      }
    }
    
    cout<<lineV[0]<<" "<<lineV[1]<<" "<<lineV[2]<<" "<<lineV[3]<<" "<<lineV[4]<<" "<<lineV[5]<<" "<<lineV[6]<<" "<<lineV[7]<<endl;
    

    
    if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
      error = 0;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -2;
    }
    else if( lineV[0] == 0 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -3;
    }
    else if( lineV[0] == 1 && lineV[1] == 1 /*&& lineV[2] == 0*/ && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -5;
    }
    else if( lineV[0] == 1 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -6;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 0 && lineV[7] == 0 ){
    error = 2;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 0 ){
    error = 3;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 &&/* lineV[5] == 0 &&*/ lineV[6] == 1 && lineV[7] == 1 ){
    error = 5;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 1 ){
    error = 6;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 10;
    if(junction == 1){error = 100;}
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -10;
    if(junction == 1){error = 100;}
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 10;
    if(junction == 1){error = 100;}
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 0 && lineV[7] == 0 ){
      error = -10;
      if(junction == 1){error = 100;}
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
      error = 10;
      if(junction == 1){error = 100;}
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
      error = -10;
      if(junction == 1){error = 100;}
    }
    else if( /*lineV[0] == 1 &&*/ lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 /* && lineV[7] == 1 */ ){
    error = 100;
    }
    else{
      cout<<"error out of index"<<endl;
      if(error == 10 || error == -10){
        error = 0;
      }
    
    }

    cout<<error<<endl;
    
    
    
    if(error == 10){
      robot->step(timeStep*18);
      left_motor->setVelocity(baseSpeed);
      right_motor->setVelocity(-baseSpeed);
      
      robot->step(timeStep*45);
      left_motor->setVelocity(0);
      right_motor->setVelocity(0);
      
      cout<<"Completed Turning 90 degrees"<<endl;
      
      robot->step(timeStep*50);
    }
    else if(error == -10){
      robot->step(timeStep*18);
      left_motor->setVelocity(-baseSpeed);
      right_motor->setVelocity(baseSpeed);
      
      
      robot->step(timeStep*45);
      
      left_motor->setVelocity(0);
      right_motor->setVelocity(0);
      
      cout<<"Completed Turning 90 degrees"<<endl;
      
      robot->step(timeStep*50);
    }
    
    else if(error == 100){ // T junction Detected
      
      TJuncFlag = 1;
      
    }
    
    
    
    else if (error < 0){
      pVal = -(error/5)*Kp;
      if(pVal > 5){
        pVal = 5;
      }
      left_motor->setVelocity(pVal-baseSpeed);
      right_motor->setVelocity(-pVal-baseSpeed);
    }
    else if (error > 0){
      pVal = (error/5)*Kp;
      if(pVal > 5){
        pVal = 5;
      }
      left_motor->setVelocity(-pVal-baseSpeed);
      right_motor->setVelocity(pVal-baseSpeed);
    }
    else{
      left_motor->setVelocity(-baseSpeed);
      right_motor->setVelocity(-baseSpeed);
    }
    
    
    
    
    if(TJuncFlag == 1){
    
      cout<<"TJuncFlag = "<<TJuncFlag<<" Junction = "<<junction<<endl;
      
      if(junction == 0){ // Starting Box
      
      cout<<"Came to Junction 0"<<endl;
      
      left_motor->setVelocity(-baseSpeed);
      right_motor->setVelocity(-baseSpeed);
      
      robot->step(timeStep*10);
      
      }
      else if(junction == 1){ // First Left T junction
      
        cout<<"Came to Junction 1"<<endl;
        
        left_motor->setVelocity(-baseSpeed);
        right_motor->setVelocity(-baseSpeed);
        
        robot->step(timeStep*10);
      
      }
      else if(junction == 2){ // Came near the stone holder
      
        cout<<"Came to Stone Holder"<<endl;
        
        left_motor->setVelocity(0);
        right_motor->setVelocity(0);
        
        robot->step(timeStep*10);
        
        cout<<"Starting Reading the Stone Holder Color"<<endl;
        
        const unsigned char *img = front_color_sensor->getImage();
        
        int stone_holder_color_green = front_color_sensor->imageGetGreen(img,64,32,32);
        int stone_holder_color_blue = front_color_sensor->imageGetBlue(img,64,32,32);
        
        cout<<"Color Green = "<<stone_holder_color_green<<" Blue - "<<stone_holder_color_blue<<endl;
        
        if(stone_holder_color_green > stone_holder_color_blue){
          stoneHolderLED->set(2);
        }
        else{
          stoneHolderLED->set(3);
        }
        
        left_motor->setVelocity(baseSpeed);
        right_motor->setVelocity(baseSpeed);
        robot->step(timeStep*5);
        
        left_motor->setVelocity(baseSpeed);
        right_motor->setVelocity(-baseSpeed);
        robot->step(timeStep*70);
        
        left_motor->setVelocity(0);
        right_motor->setVelocity(0);
        
        robot->step(timeStep*20);
      }
      
      else if(junction == 3){
        left_motor->setVelocity(-baseSpeed);
        right_motor->setVelocity(-baseSpeed);
        robot->step(timeStep*10);
        
        left_motor->setVelocity(-baseSpeed);
        right_motor->setVelocity(baseSpeed);
        robot->step(timeStep*40);
        
        left_motor->setVelocity(0);
        right_motor->setVelocity(0);
        
        robot->step(timeStep*50);
      }
      else if(junction == 4){
        left_motor->setVelocity(-baseSpeed);
        right_motor->setVelocity(-baseSpeed);
        robot->step(timeStep*10);
        
        left_motor->setVelocity(baseSpeed);
        right_motor->setVelocity(-baseSpeed);
        robot->step(timeStep*40);
        
        left_motor->setVelocity(-baseSpeed);
        right_motor->setVelocity(-baseSpeed);
        
        robot->step(timeStep*10);
      }
      
      junction++;
      TJuncFlag = 0;
    }
    
    
    
    
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}

