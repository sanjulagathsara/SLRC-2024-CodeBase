#define left_pwm 6
#define right_pwm 7
#define EN1 22
#define INB1 24
#define INA1 26
#define EN2 28
#define INB2 30
#define INA2 32


void setup(){
  

  /*
  for(int i=0;i<256;i+=5){
    move_robot(i,i);
    delay(10);
  }
  for(int i=255;i>=-255;i-=5){
    move_robot(i,i);
    delay(10);
  }
  for(int i=-255;i<=0;i+=5){
    move_robot(i,i);
    delay(10);
  }
  for(int i=0;i<256;i+=5){
    move_robot(i,-i);
    delay(10);
  }
  for(int i=255;i>=-255;i-=5){
    move_robot(i,-i);
    delay(10);
  }
  for(int i=-255;i<=0;i+=5){
    move_robot(i,-i);
    delay(10);
  }
  */
  delay(2000);
  turn_forward_left();
  delay(2000);
  turn_forward_right();


}

void loop(){

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