// File:          slrc24_controller.cpp
// Date:
// Description:
// Author: Team RoboticGen
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/motor.hpp>
#include <webots/DistanceSensor.hpp>
#include <iostream>

// All the webots classes are defined in the "webots" namespace
using namespace webots;

using namespace std;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();

  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
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
  
  //  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
    
    double val0 = lineSensor0->getValue();
    double val1 = lineSensor1->getValue();
    double val2 = lineSensor2->getValue();
    double val3 = lineSensor3->getValue();
    double val4 = lineSensor4->getValue();
    double val5 = lineSensor5->getValue();
    double val6 = lineSensor6->getValue();
    double val7 = lineSensor7->getValue();
    
    cout<<val0<<" ";
    
    
    
    
    
    
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}

