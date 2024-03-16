
#define left_base_speed 50
#define right_base_speed 50


// This code block is when starting the robot
void setup()
{
  seven_segment_setup();
  line_sensor_setup();
  motor_setup();

  Serial.begin(9600);
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
    Serial.println(pid);
    showErrorAndPID(err,pid);
    move_robot(left_base_speed-pid,right_base_speed+pid);
  }
  else if(err == 5001){
    turn_forward_right();
  }
  else if(err == 5002){
    turn_forward_left();
  }



  delay(10);

}

