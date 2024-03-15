

void setup()
{
  line_sensor_setup();
  motor_setup();

  Serial.begin(9600);
}


void loop()
{
  int err = cal_line_error();
  Serial.print(" Error = ");
  Serial.println(err);
  delay(50);
}

