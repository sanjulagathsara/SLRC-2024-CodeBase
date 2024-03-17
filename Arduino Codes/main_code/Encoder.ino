#define encoder_L_motor_Y 2
#define encoder_L_motor_G 3
#define encoder_R_motor_Y 18
#define encoder_R_motor_G 19

#define ticksPerRotation 200
#define lengthPerRotation 204.2

#define ticksPerDegree 10

volatile long countL = 0;
volatile long countR = 0;

int LDir = 0; // 1 - CW | 0 - Stationary | -1 - CCW
int RDir = 0; // 1 - CW | 0 - Stationary | -1 - CCW



void encoder_setup(){
  pinMode(encoder_L_motor_Y,INPUT);
  pinMode(encoder_L_motor_G,INPUT);
  pinMode(encoder_R_motor_Y,INPUT);
  pinMode(encoder_L_motor_G,INPUT);


}

void checkLMotorDirection(){
  if(digitalRead(encoder_L_motor_G) == HIGH){
    LDir = 1;
  }
  else{
    LDir = -1;
  }
}

void checkRMotorDirection(){
  if(digitalRead(encoder_R_motor_G) == HIGH){
    RDir = 1;
  }
  else{
    RDir = -1;
  }
}

void leftMotorPulse(){
  checkLMotorDirection();
  countL += LDir;
}


void rightMotorPulse(){
  checkRMotorDirection();
  countR += RDir;
}

void encoderForward(int length,int leftSpeed,int rightSpeed){

  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  countL = 0;
  countR = 0;

  long targetCount = (204.2/200)*length;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(!(LtargetReachFlag == 1 && RtargetReachFlag == 1)){

    if(countL >= targetCount){
      LtargetReachFlag = 1;
      move_robot(0,rightSpeed);
    }
    if(countR >= targetCount){
      RtargetReachFlag = 1;
      move_robot(leftSpeed,0);
    }
  }

  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

}

void encoderBackward(int length,int leftSpeed,int rightSpeed){

  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  countL = 0;
  countR = 0;

  long targetCount = (204.2/200)*length;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(!(LtargetReachFlag == 1 && RtargetReachFlag == 1)){

    if(countL <= -targetCount){
      LtargetReachFlag = 1;
    }
    if(countR <= -targetCount){
      RtargetReachFlag = 1;
    }

  }
  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

}



void encoderTurnLeft(int angle,int leftSpeed,int rightSpeed){

  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  countL = 0;
  countR = 0;

  long targetCount = ticksPerDegree*angle;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(!(LtargetReachFlag == 1 && RtargetReachFlag == 1)){

    if(countL <= -targetCount){
      LtargetReachFlag = 1;
      move_robot(0,rightSpeed);
    }
    if(countR >= targetCount){
      RtargetReachFlag = 1;
      move_robot(leftSpeed,0);
    }
  }

  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

}




void encoderTurnRight(int angle,int leftSpeed,int rightSpeed){


  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  countL = 0;
  countR = 0;

  long targetCount = ticksPerDegree*angle;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(!(LtargetReachFlag == 1 && RtargetReachFlag == 1)){

    if(countL >= targetCount){
      LtargetReachFlag = 1;
      move_robot(0,rightSpeed);
    }
    if(countR <= -targetCount){
      RtargetReachFlag = 1;
      move_robot(leftSpeed,0);
    }
  }

  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_Y));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

}

