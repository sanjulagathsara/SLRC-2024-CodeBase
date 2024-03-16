#include "LedControl.h"

/*

Now we need a LedControl to work with.
***** These pin numbers will probably not work with your hardware *****

pin 12 is connected to the DataIn

pin 11 is connected to the CLK

pin 10 is connected to LOAD

We have only a single MAX72XX.

*/

LedControl seven_segment=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */

unsigned long delaytime=500;

void setup() {

/* The MAX72XX is in power-saving mode on startup, we have to do a wakeup call */

seven_segment.shutdown(0,false);

/* Set the brightness to a medium values */

seven_segment.setIntensity(0,5);

/* and clear the display */

seven_segment.clearDisplay(0);
}

void hello(){

seven_segment.setChar(0,7,'H',false);

seven_segment.setChar(0,6,'e',false);

seven_segment.setChar(0,5,'l',false);

seven_segment.setChar(0,4,'l',false);

seven_segment.setChar(0,3,'0',false);



seven_segment.setDigit(0,0,3,false);

delay(delaytime);

seven_segment.setDigit(0,0,2,false);

delay(delaytime);

seven_segment.setDigit(0,0,1,false);

delay(delaytime);


seven_segment.clearDisplay(0);

delay(delaytime);

}

void loop() {
hello();

}