#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "L293.h"
#include "button.h"



int main(void)
{
	L293_init();
	initButtonOne();
	initButtonTwo();


	  while(1) {

		  if(isButtonOnePressed()) {
			  L293_clockwise();
		  } else if(isButtonTwoPressed()) {
			  L293_antiClockwise();
		  } else {
			  L293_stop();
		  }

	  }
}
