
#include "button.h"


void initButtonOne() {
	DDRD &= ~(1 << PORTD0) ;
}

void initButtonTwo() {
	DDRD &= ~(1 << PORTD1) ;
}

int isButtonOnePressed() {
	return PIND & (1<<PORTD0);
}

int isButtonTwoPressed() {
	return PIND & (1<<PORTD1);
}
