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
  
  left_motor->setVelocity(-6.28);
  right_motor->setVelocity(-6.28);
  
  lineSensor0->enable(timeStep);
  lineSensor1->enable(timeStep);
  lineSensor2->enable(timeStep);
  lineSensor3->enable(timeStep);
  lineSensor4->enable(timeStep);
  lineSensor5->enable(timeStep);
  lineSensor6->enable(timeStep);
  lineSensor7->enable(timeStep);
  
  double lineSensor[8];
  bool lineVal[8];


  std::cout << "Hello World!" << std::endl;

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
        lineVal[i] = 1;
      }
      else{
        lineVal[i] = 0;
      }
    }
    
    cout<<lineVal[0]<<" "<<lineVal[1]<<" "<<lineVal[2]<<" "<<lineVal[3]<<" "<<lineVal[4]<<" "<<lineVal[5]<<" "<<lineVal[6]<<" "<<lineVal[7]<<endl;
    
    
    
    
    
    
    
    
    
    
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}

