#define kp 0.4
#define kd 0.6
#define ki 0.01

int prev_error = 0;
float iVal = 0;




int cal_pid(int err){
  int pVal = err * kp;
  int dVal = (err - prev_error)*kd;
  prev_error = err;
  iVal += err * ki;

  if(err != prev_error){
    iVal = 0;
  }
  else if(iVal > 50){
    iVal = 50;
  }
  else if(iVal < -50){
    iVal = -50;
  }

  int pidVal = pVal + dVal + int(iVal);

  if(pidVal > left_base_speed){
    pidVal = left_base_speed;
  }
  else if(pidVal < -left_base_speed){
    pidVal = -left_base_speed;
  }

  return pidVal;
}