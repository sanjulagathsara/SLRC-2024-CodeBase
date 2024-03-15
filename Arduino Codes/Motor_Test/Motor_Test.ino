#define left_pwm 6
#define right_pwm 7
#define EN1 22
#define INB1 24
#define INA1 26
#define EN2 28
#define INB2 30
#define INA2 32

void setup(){
  pinMode(left_pwm,OUTPUT);
  pinMode(right_pwm,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(INB1,OUTPUT);
  pinMode(INA1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(INA2,OUTPUT);

  digitalWrite(EN1,HIGH);
  digitalWrite(EN2,HIGH);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);
  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  for(int i=0;i<256;i++){
    analogWrite(left_pwm,i);
    analogWrite(right_pwm,i);
    delay(10);
  }
  for(int i=255;i>=0;i--){
    analogWrite(left_pwm,i);
    analogWrite(right_pwm,i);
    delay(10);
  }

}

void loop(){

}

void go_forward(int left_speed,int right_speed){
  
}