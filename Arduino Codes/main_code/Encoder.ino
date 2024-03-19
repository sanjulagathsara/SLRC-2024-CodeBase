//pins
#define encoder_L_motor_Y 18
#define encoder_L_motor_G 19
#define encoder_R_motor_Y 2
#define encoder_R_motor_G 3

#define ticksPerRotation 234
#define lengthPerRotation 204.2

#define ticksPerDegree 3.3

volatile int countL = 0;
volatile int countR = 0;

int LDir = 0; // 1 - CW | 0 - Stationary | -1 - CCW
int RDir = 0; // 1 - CW | 0 - Stationary | -1 - CCW

volatile bool right_motor_direction = HIGH; // Forward



void encoder_setup(){
  pinMode(encoder_L_motor_Y,INPUT);
  pinMode(encoder_L_motor_G,INPUT);
  pinMode(encoder_R_motor_Y,INPUT);
  pinMode(encoder_L_motor_G,INPUT);


}

void checkLMotorDirection(){
  if(digitalRead(encoder_L_motor_Y) == HIGH){
    LDir = 1;
  }
  else{
    LDir = -1;
  }
}

void checkRMotorDirection(){
  if(right_motor_direction == HIGH){
    RDir = 1;
  }
  else{
    RDir = -1;
  }
}

void leftMotorPulse(){
  checkLMotorDirection();
  countL += LDir;
  if(countL > 32000){
    countL = 0;
  }
  else if(countL < -32000){
    countL = 0;
  }
}


void rightMotorPulse(){
  checkRMotorDirection();
  countR += RDir;
  if(countR > 32000){
    countR = 0;
  }
  else if(countR < -32000){
    countR = 0;
  }
}

void encoderForward(int length,int leftSpeed,int rightSpeed){

  right_motor_direction = HIGH;

  countL = 0;
  countR = 0;

  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_G),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);
  

  

  long targetCount = (204.2/200)*length;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(!(LtargetReachFlag == 1 && RtargetReachFlag == 1)){
    //Serial.print("Encoder forward countL = ");
    //Serial.print(countL);
    //Serial.print(" countR = ");
    //Serial.println(countR);

    if(countL >= targetCount && LtargetReachFlag == 0){
      LtargetReachFlag = 1;
      move_robot(0,rightSpeed);
    }
    if(countR >= targetCount && RtargetReachFlag == 0){
      RtargetReachFlag = 1;
      move_robot(leftSpeed,0);
    }
  }


  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_G));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

  brake_fast();

}

void encoderBackward(int length,int leftSpeed,int rightSpeed){

  right_motor_direction = LOW;

  countL = 0;
  countR = 0;

  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_G),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  

  long targetCount = (204.2/200)*length;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(!(LtargetReachFlag == 1 && RtargetReachFlag == 1)){

    Serial.print("Left = ");
    Serial.print(countL);
    Serial.print(" Right = ");
    Serial.print(countR);

    if(countL <= -targetCount && LtargetReachFlag == 0){
      LtargetReachFlag = 1;
      move_robot(0,rightSpeed);
    }
    if(countR <= -targetCount && RtargetReachFlag == 0){
      RtargetReachFlag = 1;
      move_robot(leftSpeed,0);
    }

  }


  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_G));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

  brake_fast();
}



void encoderTurnLeft(int angle,int leftSpeed,int rightSpeed){

  right_motor_direction = HIGH;

  countL = 0;
  countR = 0;

  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_G),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  

  long targetCount = ticksPerDegree*angle;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(true){
    if((countL-countR) <= -targetCount){
      break;
    }
  }

  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_G));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

  brake_fast();


}




void encoderTurnRight(int angle,int leftSpeed,int rightSpeed){

  right_motor_direction = LOW;

  countL = 0;
  countR = 0;


  attachInterrupt(digitalPinToInterrupt(encoder_L_motor_G),leftMotorPulse,RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y),rightMotorPulse,RISING);

  
  long targetCount = ticksPerDegree*angle;

  move_robot(leftSpeed,rightSpeed);

  bool LtargetReachFlag = 0;
  bool RtargetReachFlag = 0;

  while(true){

  if((countL-countR) >= targetCount){
    break;
  }

  }

  detachInterrupt(digitalPinToInterrupt(encoder_L_motor_G));
  detachInterrupt(digitalPinToInterrupt(encoder_R_motor_Y));

  brake_fast();

  

}

void encoderForwardRight(int leftSpeed,int rightSpeed){

  encoderForward(80,leftSpeed,rightSpeed);
  encoderTurnRight(90,leftSpeed,-rightSpeed);

}


void encoderForwardLeft(int leftSpeed,int rightSpeed){

  encoderForward(80,leftSpeed,rightSpeed);
  encoderTurnLeft(90,-leftSpeed,rightSpeed);

}

