#define servo1 8
#define servo2 9
#define servo3 4

#include <Servo.h>

Servo liftServo;
Servo jawServo1;
Servo jawServo2;

void servo_setup(){
liftServo.attach(servo1);
jawServo1.attach(servo2);
jawServo2.attach(servo3);
liftUp();
jawOpen();
}

void liftUp(){
  liftServo.write(10);
}

void liftDown()
{
  liftServo.write(100);
}

void jawClose(){
  jawServo1.write(30);
  jawServo2.write(30);
}

void jawOpen(){
  jawServo1.write(170);
  jawServo2.write(170);
}
