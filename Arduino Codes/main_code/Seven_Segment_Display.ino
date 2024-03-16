#include "LedControl.h"

LedControl seven_segment=LedControl(12,11,10,1);

/*

pin 12 is connected to the DataIn

pin 11 is connected to the CLK

pin 10 is connected to LOAD

We have only a single MAX72XX.

*/

void seven_segment_setup(){

/* The MAX72XX is in power-saving mode on startup, we have to do a wakeup call */

seven_segment.shutdown(0,false);

/* Set the brightness to a medium values */

seven_segment.setIntensity(0,5);

/* and clear the display */

seven_segment.clearDisplay(0);

seven_segment.setChar(0,7,'H',false);

seven_segment.setChar(0,6,'e',false);

seven_segment.setChar(0,5,'l',false);

seven_segment.setChar(0,4,'l',false);

seven_segment.setChar(0,3,'0',false);



seven_segment.setDigit(0,0,3,false);

delay(1000);

seven_segment.setDigit(0,0,2,false);

delay(1000);

seven_segment.setDigit(0,0,1,false);

delay(1000);


seven_segment.clearDisplay(0);

}

void showError(int err){
  seven_segment.clearDisplay(0);
  if(err < 0){
    seven_segment.setChar(0,7,'-',false);
    err = -err;
  }
  else{
    seven_segment.setChar(0,7,' ',false);
  }

  if(err<10){
    seven_segment.setDigit(0,4,err,false);
  }
  else if(err<100){
    seven_segment.setDigit(0,5,err/10,false);
    seven_segment.setDigit(0,4,err%10,false);
  }
  else if(err<1000){
    seven_segment.setDigit(0,6,err/100,false);
    seven_segment.setDigit(0,5,(err/10)%10,false);
    seven_segment.setDigit(0,4,err%10,false);
  }

}

void showErrorAndPID(int err,int pid){
  seven_segment.clearDisplay(0);
  if(err < 0){
    seven_segment.setChar(0,7,'-',false);
    err = -err;
  }
  else{
    seven_segment.setChar(0,7,' ',false);
  }

  if(err<10){
    seven_segment.setDigit(0,4,err,false);
  }
  else if(err<100){
    seven_segment.setDigit(0,5,err/10,false);
    seven_segment.setDigit(0,4,err%10,false);
  }
  else if(err<1000){
    seven_segment.setDigit(0,6,err/100,false);
    seven_segment.setDigit(0,5,(err/10)%10,false);
    seven_segment.setDigit(0,4,err%10,false);
  }

  if(pid < 0){
    seven_segment.setChar(0,3,'-',false);
    pid = -pid;
  }
  else{
    seven_segment.setChar(0,3,' ',false);
  }

  if(pid<10){
    seven_segment.setDigit(0,0,pid,false);
  }
  else if(pid<100){
    seven_segment.setDigit(0,1,pid/10,false);
    seven_segment.setDigit(0,0,pid%10,false);
  }
  else{
    seven_segment.setDigit(0,2,pid/100,false);
    seven_segment.setDigit(0,1,(pid/10)%10,false);
    seven_segment.setDigit(0,0,pid%10,false);
  }

}