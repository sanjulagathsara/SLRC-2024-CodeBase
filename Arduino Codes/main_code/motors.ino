// This code is for Controlling Motors

#define left_pwm 6
#define right_pwm 7
#define EN1 22
#define INB1 24
#define INA1 26
#define EN2 28
#define INB2 30
#define INA2 32

void motor_setup(){
  pinMode(left_pwm,OUTPUT); // Setting pinModes
  pinMode(right_pwm,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(INB1,OUTPUT);
  pinMode(INA1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(INA2,OUTPUT);

  digitalWrite(EN1,HIGH); // Enabling Motors
  digitalWrite(EN2,HIGH);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,LOW);
  digitalWrite(INA2,LOW);
  digitalWrite(INB2,LOW);
}

void move_robot(int left_speed,int right_speed){

    if(left_speed>=0){
      digitalWrite(INA1,LOW);
      digitalWrite(INB1,HIGH);
      analogWrite(left_pwm,left_speed);
    }
    else{
      digitalWrite(INA1,HIGH);
      digitalWrite(INB1,LOW);
      analogWrite(left_pwm,-left_speed);
    }


    if(right_speed>=0){
      digitalWrite(INA2,LOW);
      digitalWrite(INB2,HIGH);
      analogWrite(right_pwm,right_speed);
    }
    else{
      digitalWrite(INA2,HIGH);
      digitalWrite(INB2,LOW);
      analogWrite(right_pwm,-right_speed);
    }

}

void brake(){
      digitalWrite(INA2,LOW);
      digitalWrite(INB2,LOW);
      digitalWrite(INA1,LOW);
      digitalWrite(INB1,LOW);
      analogWrite(left_pwm,0);
      analogWrite(right_pwm,0);
}

void brake_fast(){
      digitalWrite(INA2,HIGH);
      digitalWrite(INB2,HIGH);
      digitalWrite(INA1,HIGH);
      digitalWrite(INB1,HIGH);
      analogWrite(left_pwm,0);
      analogWrite(right_pwm,0);
}

void turn_left(){
    move_robot(-60,60);
    delay(680);
    brake_fast();
}

void turn_right(){
    move_robot(60,-60);
    delay(680);
    brake_fast();
}

void turn_forward_left(){
    move_robot(60,60);
    delay(500);
    move_robot(-60,60);
    delay(680);
    brake_fast();
}

void turn_forward_right(){
    move_robot(60,60);
    delay(500);
    move_robot(60,-60);
    delay(680);
    brake_fast();
}
