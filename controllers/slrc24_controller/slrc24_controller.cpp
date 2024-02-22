// File:          slrc24_controller.cpp
// Date:
// Description:
// Author: Team RoboticGen
// Modifications:

#include <webots/Robot.hpp>
#include <webots/motor.hpp>
#include <webots/DistanceSensor.hpp>

#include <iostream>

using namespace webots;

using namespace std;


int main(int argc, char **argv) {

  // create the Robot instance.
  Robot *robot = new Robot();


  int timeStep = (int)robot->getBasicTimeStep();
  
  double lineSensor[8];
  bool lineV[8];
  float pVal;
  float Kp = 5;
  float baseSpeed = 5;
  bool TJuncFlag = 0;
  
  int junction = 0;
  
  int error = 0;


  Motor *left_motor = robot->getMotor("left_motor");
  Motor *right_motor = robot->getMotor("right_motor");
  
  DistanceSensor *lineSensor0 = robot->getDistanceSensor("lineSensor0");
  DistanceSensor *lineSensor1 = robot->getDistanceSensor("lineSensor1");
  DistanceSensor *lineSensor2 = robot->getDistanceSensor("lineSensor2");
  DistanceSensor *lineSensor3 = robot->getDistanceSensor("lineSensor3");
  DistanceSensor *lineSensor4 = robot->getDistanceSensor("lineSensor4");
  DistanceSensor *lineSensor5 = robot->getDistanceSensor("lineSensor5");
  DistanceSensor *lineSensor6 = robot->getDistanceSensor("lineSensor6");
  DistanceSensor *lineSensor7 = robot->getDistanceSensor("lineSensor7");

  
  left_motor->setPosition(INFINITY);
  right_motor->setPosition(INFINITY);
  
  left_motor->setVelocity(-baseSpeed);
  right_motor->setVelocity(-baseSpeed);
  
  lineSensor0->enable(timeStep);
  lineSensor1->enable(timeStep);
  lineSensor2->enable(timeStep);
  lineSensor3->enable(timeStep);
  lineSensor4->enable(timeStep);
  lineSensor5->enable(timeStep);
  lineSensor6->enable(timeStep);
  lineSensor7->enable(timeStep);
  
  

  std::cout << "Robot is Starting!" << std::endl;

  // Main loop:

  while (robot->step(timeStep) != -1) {
    
    

    
    lineSensor[0] = lineSensor0->getValue();
    lineSensor[1] = lineSensor1->getValue();
    lineSensor[2] = lineSensor2->getValue();
    lineSensor[3] = lineSensor3->getValue();
    lineSensor[4] = lineSensor4->getValue();
    lineSensor[5] = lineSensor5->getValue();
    lineSensor[6] = lineSensor6->getValue();
    lineSensor[7] = lineSensor7->getValue();
    
    //cout<<lineSensor[0]<<" "<<lineSensor[1]<<" "<<lineSensor[2]<<" "<<lineSensor[3]<<" "<<lineSensor[4]<<" "<<lineSensor[5]<<" "<<lineSensor[6]<<" "<<lineSensor[7]<<endl;
    
    
    for(int i=0;i<8;i++){
      if(lineSensor[i] < 500){
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
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -4;
    }
    else if( lineV[0] == 1 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -5;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 0 && lineV[7] == 0 ){
    error = 2;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 0 ){
    error = 3;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 4;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 1 ){
    error = 5;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 10;
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -10;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 10;
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -10;
    }
    else if( lineV[0] == 0 && lineV[1] == 0 && lineV[2] == 0 && lineV[3] == 0 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 10;
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 0 && lineV[5] == 0 && lineV[6] == 0 && lineV[7] == 0 ){
    error = -10;
    }
    else if( lineV[0] == 1 && lineV[1] == 1 && lineV[2] == 1 && lineV[3] == 1 && lineV[4] == 1 && lineV[5] == 1 && lineV[6] == 1 && lineV[7] == 1 ){
    error = 100;
    }
    else{
    //error = error;
    if(error == 10 || error == -10){
      error = 0;
    }
    
    }

    cout<<error<<endl;
    
    
    
    if(error == 10){
      robot->step(timeStep*18);
      left_motor->setVelocity(-baseSpeed);
      right_motor->setVelocity(baseSpeed);
      
      robot->step(timeStep*45);
      left_motor->setVelocity(0);
      right_motor->setVelocity(0);
      
      cout<<"Completed Turning 90 degrees"<<endl;
      
      robot->step(timeStep*50);
    }
    else if(error == -10){
      robot->step(timeStep*18);
      left_motor->setVelocity(baseSpeed);
      right_motor->setVelocity(-baseSpeed);
      
      
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
      
      if(junction == 0){
      
      }
      
      junction++;
      TJuncFlag = 0;
    }
    
    
    
    
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}

