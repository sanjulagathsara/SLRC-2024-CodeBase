
#define left_base_speed 50
#define right_base_speed 50
#define motor_offset 8





int robot_status = 0;


// This code block is when starting the robot
void setup()
{
  seven_segment_setup();
  line_sensor_setup();
  motor_setup();
  Serial.begin(9600);
  setup_sound();
}

// This code block is when the robot is running
void loop()
{

  if(robot_status == 0){ // Initial State at Start Box
    move_robot(left_base_speed,right_base_speed);
    delay(500);
    robot_status = 1;
  }



  else if(robot_status%2 == 1){ // Robot at Line Segments
  
  
    int err = cal_line_error();


    if(err  <= 5000){
      
      int pid = cal_pid(err);
      Serial.print(" Error = ");
      Serial.print(err);
      Serial.print(" pid = ");
      Serial.println(pid);
      showErrorAndPID(pid,robot_status);
      move_robot(left_base_speed+pid+motor_offset/2,right_base_speed-pid-motor_offset/2);
    }
    else if(err == 5001){ // Junction to right
      beep(2,20);
      robot_status += 1;
    }
    else if(err == 5002){ // Junction to left
      beep(1,20);
      robot_status += 1;
    }
    else if(err == 5003){ // T junction
      beep(3,20);
      robot_status += 1; 

    }

  }

  else if(robot_status == 2){ // Robot at First Junction
    brake_fast();
    delay(1000);
    move_robot(left_base_speed,right_base_speed);
    delay(500);
    robot_status += 1;
  }
  else if(robot_status == 4){ // Robot at First Gem Holder
  brake_fast();
  delay(1000);
  turn_left_180();
  robot_status += 1;
  }

  else if(robot_status == 6){ // Robot at First Junction Second Time
  brake_fast();
  delay(1000);
  turn_forward_right();
  robot_status += 1;
  }

  else if(robot_status == 8){ 
  brake_fast();
  delay(1000);
  turn_forward_right();
  robot_status += 1;
  }

  else if(robot_status == 10){ 
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 12){ // Robot at colour round
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 14){ // Robot at junction before circle
  brake_fast();
  delay(1000);
  turn_forward_right();
  robot_status += 1;
  }

  else if(robot_status == 16){ // Robot Entering Circle
  brake_fast();
  delay(1000);
  turn_forward_right();
  robot_status += 1;
  }

  else if(robot_status == 18){ // Robot Departing Circle
  brake_fast();
  delay(1000);
  turn_forward_right();
  robot_status += 1;
  }

  else if(robot_status == 20){ // Robot Departing Circle junction
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 22){ // Robot Colour Circle to metal boxes
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 24){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  move_robot(left_base_speed,right_base_speed);
  delay(400);
  robot_status += 1;
  }

  else if(robot_status == 26){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  turn_left_180();
  robot_status += 1;
  }

  else if(robot_status == 28){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  turn_forward_right();
  robot_status += 1;
  }

  else if(robot_status == 30){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  turn_left_180();
  robot_status += 1;
  }

  else if(robot_status == 32){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  move_robot(left_base_speed,right_base_speed);
  delay(400);
  robot_status += 1;
  }

  else if(robot_status == 34){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  turn_right_180();
  robot_status += 1;
  }

  else if(robot_status == 36){ // Robot search metal boxes
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 38){ // Go forward 4 junction
  brake_fast();
  delay(1000);
  move_robot(left_base_speed,right_base_speed);
  delay(400);
  robot_status += 1;
  }

  else if(robot_status == 40){ // Robot left to put the box
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 42){ // Putting down metal box
  brake_fast();
  delay(1000);
  turn_right_180();
  robot_status += 1;
  }

  else if(robot_status == 44){ // Robot left to put the box
  brake_fast();
  delay(1000);
  turn_forward_left();
  robot_status += 1;
  }

  else if(robot_status == 46){ // End
  brake_fast();
  delay(1000);
  move_robot(left_base_speed,right_base_speed);
  delay(1000);
  brake();
  beep(5,100);
  while(true){}
  }

  else if(robot_status == 66){ // Debug go forward
  move_robot(left_base_speed,right_base_speed);
  }
  else if(robot_status == 68){ // Debug ir values
      int err = cal_line_error();
      Serial.print(" Error = ");
      Serial.println(err);
  }

  else{
    beep(5,100);
    brake();
  }

  delay(10);

}

