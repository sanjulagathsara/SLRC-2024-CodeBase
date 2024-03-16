#define kp 0.5
#define kd 0.5
#define ki 0

int prev_error = 0;
int iVal = 0;




int cal_pid(int err){
  int pVal = err * kp;
  int dVal = (err - prev_error)*kd;
  prev_error = err;
  iVal += err * ki;
  if(iVal > 10000){
    iVal = 10000;
  }
  else if(iVal < -10000){
    iVal = -10000;
  }

  int pidVal = pVal + dVal + iVal;

  if(pidVal > 999){
    pidVal = 999;
  }
  else if(pidVal < -999){
    pidVal = -999;
  }

  return pidVal;
}