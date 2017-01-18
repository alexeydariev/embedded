#include "uart_stdio.h"

FILE my_stream = FDEV_SETUP_STREAM(uart_PutChar, NULL, _FDEV_SETUP_WRITE);

void uart_Stdio_Init(void) {
	
	stdout = &my_stream;

	#if F_CPU < 2000000UL && defined(U2X)
	UCSRA = _BV(U2X);             /* improve baud rate error (2x clock) */
	UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
	#else
	UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
	#endif
	UCSRB = _BV(TXEN) | _BV(RXEN); /* enable transmitter and receiver registers*/
}

int uart_PutChar(char c, FILE *stream) {
	
	if (c == '\n')
	uart_PutChar('\r', stream);
	
	while (~UCSRA & (1 << UDRE));
	UDR = c;

	return 0;
}
