

void setup()
{
  line_sensor_setup();
  motor_setup();

  Serial.begin(9600);
  delay(2000);
}


void loop()
{
  int err = cal_line_error();
  Serial.print(" Error = ");
  Serial.println(err);
  cal_pid();
  move_robot(60+(err/20),60-(err/20));
  delay(50);
}

