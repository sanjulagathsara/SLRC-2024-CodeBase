#define blue_led 48
#define green_led 50

void LED_setup(){
  pinMode(blue_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  digitalWrite(green_led,HIGH);
  digitalWrite(blue_led,HIGH);
}

void set_led_color(int color){ //Color : Green 0 - Blue 1
  if(color == 0){
    digitalWrite(green_led,LOW);
    digitalWrite(blue_led,HIGH);
  }
  else{
    digitalWrite(green_led,HIGH);
    digitalWrite(blue_led,LOW);
  }
}

void error_blink(int count){
  for(int i=0;i<count;i++){
    digitalWrite(green_led,LOW);
    digitalWrite(blue_led,LOW);
    delay(200);
    digitalWrite(green_led,HIGH);
    digitalWrite(blue_led,HIGH);
  }
}

void led_off(){
  digitalWrite(green_led,HIGH);
  digitalWrite(blue_led,HIGH);
}