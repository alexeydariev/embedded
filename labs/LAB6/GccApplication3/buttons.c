#include "buttons.h"

#define MASK_BUTTONS 	        ((1<<DOWN)|(1<<UP)|(1<<ENTER))
#define ClearBit(reg, bit)      (reg) &= (~(1<<(bit)))
#define SetBit(reg, bit)        (reg) |= (1<<(bit))	
#define BitIsClear(reg, bit)    ((reg & (1<<(bit))) == 0)
#define BitIsSet(reg, bit)      ((reg & (1<<(bit))) != 0)

unsigned char comp = 0;

//_______________________________________
void BUT_Init(void)
{
  DDRX_BUTTON &= ~(MASK_BUTTONS); 
  PORT_BUTTON |= MASK_BUTTONS;
}

//_______________________________________
void BUT_Debrief(void)
{
unsigned char key = 0;

  //последовательный опрос выводов мк
  if (BitIsClear(PIN_BUTTON, UP))     
    key = EVENT_KEY_UP;
  else if (BitIsClear(PIN_BUTTON, DOWN))    
    key = EVENT_KEY_DOWN;
  else if (BitIsClear(PIN_BUTTON, ENTER))        
    key = EVENT_KEY_ENTER;    
  else {
    key = EVENT_NULL;
  }

  //если во временной переменной что-то есть
  if (key) {
    //и если кнопка удерживается долго
    //записать ее номер в буфер 
    if (comp == THRESHOLD) {
      comp = THRESHOLD+10; 
      ES_PlaceEvent(key);
      return;
    }
    else{
      if (comp < (THRESHOLD+5)){ comp++;}
    }
	
  } 
  else comp=0;
}



