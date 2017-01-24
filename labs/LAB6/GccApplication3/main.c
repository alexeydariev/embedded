#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd_lib.h"
#include "buttons.h"
#include "event-system.h"
#include "interface.h"
#include "timer.h"

int main( void )
{
  unsigned char event = 0;

  LCD_Init();
  BUT_Init();
  TIM_Init();
  ES_Init();
  GUI_General();
  
  sei();  
  while(1){
	event = ES_GetEvent();
    if (event){
       ES_Dispatch(event);
    }
  }
  
  return 0;
}
