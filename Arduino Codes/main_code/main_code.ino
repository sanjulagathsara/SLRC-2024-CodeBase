
#define left_base_speed 60
#define right_base_speed 60


// This code block is when starting the robot
void setup()
{
  seven_segment_setup();
  line_sensor_setup();
  motor_setup();

  Serial.begin(9600);
  delay(2000);
}

// This code block is when the robot is running
void loop()
{
  
  int err = cal_line_error();


  if(err  <= 5000){
    
    int pid = cal_pid(err);
    Serial.print(" Error = ");
    Serial.print(err);
    Serial.print(" pid = ");
    pid = pid/20;
    Serial.println(pid);
    showError(pid);
    //move_robot(left_base_speed+pid,right_base_speed-pid);
    delay(50);
  }
  else if(err == 5001){
    turn_forward_left();
  }
  else if(err == 5002){
    turn_forward_right();
  }





}

