const int trigPin = 14;  
const int echoPin = 15; 

void ultrasonic_setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
}  

int getFrontDistance(){
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration*.0343)/2; 


  Serial.print("Distance: ");
  Serial.println(distance);

  return distance; 
}