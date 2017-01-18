#include <avr/io.h>
#include <avr/delay.h>
#include "uart/uart_stdio.h"

int count = 0;

void main() {
	uart_Stdio_Init();
	
	while(1){
		count = count + 1;
		printf("%d\n",count);
		_delay_ms(1000);
	}
}
