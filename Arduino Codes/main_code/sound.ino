//pins
#define buzzer 5

void sound_setup(){
  pinMode(buzzer,OUTPUT);
  beep(4,100);
}

void beep(int count,int delay1){

  for(int i =0;i<count;i++){
    digitalWrite(buzzer,LOW);
    delay(delay1);
    digitalWrite(buzzer,HIGH);
    delay(delay1);
  }
}