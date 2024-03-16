#define buzzer 13

void setup_sound(){
  pinMode(buzzer,OUTPUT);
  beep(4,100);
}

void beep(int count,int delay1){

  for(int i =0;i<count;i++){
    digitalWrite(buzzer,HIGH);
    delay(delay1);
    digitalWrite(buzzer,LOW);
    delay(delay1);
  }
}