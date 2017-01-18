#include <avr/delay.h>
#include "lcd/lcd_hd44780_avr.h"
#include "usart/usart.h"
#include "adc/adc.h"
#include "LM20/lm20.h"

struct Button *btnKelvin;
struct Button *btnFarenheit;

void initButtons();
void outputOnLCD(char *msg, char *buffer, int value);
void checkTConversion(char *buffer, int value);

int main(void) {
	
	unsigned int value;
	char buffer[3];
	
	initButtons();
	USARTInit();
	LM20_Init();
	LCDInit(LS_NONE);
	
	while(1) {
		value = LM20_GetCelsiusValue(value);
		itoa(value, buffer, 10); 
		_delay_ms(50);
		checkTConversion(buffer, value);
	}
}


void checkTConversion(char *buffer, int value) {
	
	if (isButtonPressed(&btnKelvin)) {
		value = convertToKelvin(value);
		outputOnLCD("T%0 K = ", buffer, value);
	} else if (isButtonPressed(&btnFarenheit)) {
		value = convertToFarenheit(value);
		outputOnLCD("T%0 Ft = ", buffer, value);
	} else {
		outputOnLCD("T%0 C = ", buffer, value);
	}
}

void initButtons() {
	initButton(&btnKelvin, PINC0, &DDRC, &PINC); // init button
	setButtonDDR(&btnKelvin);
	
	initButton(&btnFarenheit, PINC4, &DDRC, &PINC); // init button
	setButtonDDR(&btnFarenheit);
}

void outputOnLCD(char *msg, char *buffer, int value) {
	itoa(value, buffer, 10);
	LCDGotoXY(0,0);
	LCDWriteString(msg);
	LCDGotoXY(0,1);
	LCDWriteString("    ");
	LCDGotoXY(0,1);
	LCDWriteString( buffer);
}