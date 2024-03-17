/*  Team RoboticGen

Code for SLRC 2024

Team : Sanjula Gathsara, Nimeth Menuka, Mineth Banula, Yasantha Niroshan

Every code line is Copyright Protected

© 2024 RoboticGen Inc <hello@Roboticgen.lk>

*/

#define left_base_speed 80
#define right_base_speed 80
#define motor_offset 8

//This variable handles the Main State Change of the Robot
int robot_state = 0;


// This code block is when starting the robot
void setup()
{
  Serial.begin(9600); // Beginning Serial Communication
  Serial.println("Robot is Starting : Team RoboticGen - SLRC 2024"); 
  seven_segment_setup();
  line_sensor_setup();
  motor_setup();
  sound_setup();
  encoder_setup();
}

// This code block is when the robot is running
void loop()
{

  if(robot_state == 0){ // Initial State at Start Box
    move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
    delay(500);
    robot_state = 1;
  }


  else if(robot_state%2 == 1){ // Robot at Line Segments
  
  
    int err = cal_line_error();


    if(err  <= 5000){
      
      int pid = cal_pid(err);
      Serial.print(" Error = ");
      Serial.print(err);
      Serial.print(" pid = ");
      Serial.println(pid);
      showErrorAndPID(pid,robot_state);
      move_robot(left_base_speed+pid+motor_offset/2,right_base_speed-pid-motor_offset/2);
    }
    else if(err == 5001){ // Junction to right
      beep(2,20);
      robot_state += 1;
    }
    else if(err == 5002){ // Junction to left
      beep(1,20);
      robot_state += 1;
    }
    else if(err == 5003){ // T junction
      beep(3,20);
      robot_state += 1; 

    }

  }

  else{     // The code that executes in junctions

    if(robot_state == 2){ // Robot at First Junction
      brake_fast();
      delay(1000);
      move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
      delay(500);
      robot_state += 1;
    }


    else if(robot_state == 4){ // Robot at First Gem Holder
    brake_fast();
    delay(1000);
    turn_left_180();
    robot_state += 1;
    }

    else if(robot_state == 6){ // Robot at First Junction Second Time
    brake_fast();
    delay(1000);
    turn_forward_right();
    robot_state += 1;
    }

    else if(robot_state == 8){ 
    brake_fast();
    delay(1000);
    turn_forward_right();
    robot_state += 1;
    }

    else if(robot_state == 10){ 
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 12){ // Robot at colour round
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 14){ // Robot at junction before circle
    brake_fast();
    delay(1000);
    turn_forward_right();
    robot_state += 1;
    }

    else if(robot_state == 16){ // Robot Entering Circle
    brake_fast();
    delay(1000);
    turn_forward_right();
    robot_state += 1;
    }

    else if(robot_state == 18){ // Robot Departing Circle
    brake_fast();
    delay(1000);
    turn_forward_right();
    robot_state += 1;
    }

    else if(robot_state == 20){ // Robot Departing Circle junction
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 22){ // Robot Colour Circle to metal boxes
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 24){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
    delay(400);
    robot_state += 1;
    }

    else if(robot_state == 26){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    turn_left_180();
    robot_state += 1;
    }

    else if(robot_state == 28){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    turn_forward_right();
    robot_state += 1;
    }

    else if(robot_state == 30){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    turn_left_180();
    robot_state += 1;
    }

    else if(robot_state == 32){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
    delay(400);
    robot_state += 1;
    }

    else if(robot_state == 34){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    turn_right_180();
    robot_state += 1;
    }

    else if(robot_state == 36){ // Robot search metal boxes
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 38){ // Go forward 4 junction
    brake_fast();
    delay(1000);
    move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
    delay(400);
    robot_state += 1;
    }

    else if(robot_state == 40){ // Robot left to put the box
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 42){ // Putting down metal box
    brake_fast();
    delay(1000);
    turn_right_180();
    robot_state += 1;
    }

    else if(robot_state == 44){ // Robot left to put the box
    brake_fast();
    delay(1000);
    turn_forward_left();
    robot_state += 1;
    }

    else if(robot_state == 46){ // End
    brake_fast();
    delay(1000);
    move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
    delay(1000);
    brake();
    beep(5,100);
    while(true){}
    }

    /*****************************************************************************************************************************************
    ***********************************       Debugging Codes     ****************************************************************************
    ******************************************************************************************************************************************/

    else if(robot_state == 164){ // Debug go Backward
    move_robot(-(left_base_speed+motor_offset/2),-(right_base_speed-motor_offset/2));
    }

    else if(robot_state == 166){ // Debug go forward
    move_robot(left_base_speed+motor_offset/2,right_base_speed-motor_offset/2);
    }
    else if(robot_state == 168){ // Debug ir values
        int err = cal_line_error();
        Serial.print(" Error = ");
        Serial.println(err);
    }

    else if(robot_state == 170){ // PID Tuning
        int analogIn0 = analogRead(A1);
        //int analogIn1 = analogRead(A0);
        float var0 = analogIn0/10000.0;
        //float var1 = analogIn1/500.0;
        //setkp(var0);
        //setkd(var1);
        //setki(var0);
        Serial.print(" pot = ");
        Serial.print(var0);
        int err = cal_line_error();
        int pid = cal_pid(err);
        Serial.print(" Error = ");
        Serial.print(err);
        Serial.print(" pid = ");
        Serial.println(pid);
        showErrorAndPID(var0*10000,err);
        move_robot(left_base_speed+pid+motor_offset/2,right_base_speed-pid-motor_offset/2);
    }

    else{
      beep(5,100);
      brake();
    }
  }
  delay(10);

}

