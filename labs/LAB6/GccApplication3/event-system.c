
#include "event-system.h"

//кольцевой буфер
static volatile unsigned char cycleBuf[SIZE_BUF];
static volatile unsigned char tailBuf = 0;
static volatile unsigned char headBuf = 0;
static volatile unsigned char countBuf = 0;

//взять событие
unsigned char ES_GetEvent(void)
{
  unsigned char event;
  if (countBuf > 0){                    //если приемный буфер не пустой  
    event = cycleBuf[headBuf];          //считать из него событие    
    countBuf--;                         //уменьшить счетчик 
    headBuf++;                          //инкрементировать индекс головы буфера  
    if (headBuf == SIZE_BUF) headBuf = 0;
    return event;                         //вернуть событие
  }
  return 0;
}

//положить событие
void ES_PlaceEvent(unsigned char event) 
{
  if (countBuf < SIZE_BUF){                    //если в буфере еще есть место                     
      cycleBuf[tailBuf] = event;               //кинуть событие в буфер
      tailBuf++;                               //увеличить индекс хвоста буфера 
      if (tailBuf == SIZE_BUF) tailBuf = 0;  
      countBuf++;                              //увеличить счетчик 
  }
} 

//*****************************************************************************

volatile unsigned char currentState = 0;

typedef struct PROGMEM 
{
    unsigned char state;           //состояние
    unsigned char event;           //событие
    unsigned char nextState;       //следующее состояние
    void (*pStateFunc)(void);                       
}ROW_TABLE;

void ES_Init(void)
{
  tailBuf = 0;
  headBuf = 0;
  countBuf = 0;
  currentState = STATE_NORMAL;
}


ROW_TABLE const table[] PROGMEM  = {
//  STATE                    EVENT                NEXT STATE              STATE_FUNC    
    {STATE_NORMAL,       EVENT_KEY_ENTER,       STATE_SET_HOUR,         GUI_SelectHour},
    {STATE_NORMAL,       EVENT_SYS_TIMER,       STATE_NO_CHANGE,        GUI_ChangeTime},
    
    {STATE_SET_HOUR,     EVENT_KEY_ENTER,       STATE_SET_MINUTE,       GUI_SelectMinute},
    {STATE_SET_HOUR,     EVENT_KEY_UP,          STATE_NO_CHANGE,        GUI_IncHour},
    {STATE_SET_HOUR,     EVENT_KEY_DOWN,        STATE_NO_CHANGE,        GUI_DecHour},
    
    {STATE_SET_MINUTE,   EVENT_KEY_ENTER,       STATE_NORMAL,           GUI_General},
    {STATE_SET_MINUTE,   EVENT_KEY_UP,          STATE_NO_CHANGE,        GUI_IncMinute},
    {STATE_SET_MINUTE,   EVENT_KEY_DOWN,        STATE_NO_CHANGE,        GUI_DecMinute},  
    {        0,                0,                   0,                      NULL}
};

#define prb(data) pgm_read_byte(&(data))
#define prw(data) pgm_read_word(&(data))

void ES_Dispatch(unsigned char currentEvent)
{
    void (*pStateFunc)(void);
    unsigned char i;
      
    pStateFunc = NULL;    
    
    for (i=0; prb(table[i].state); i++)
    {
        if (prb(table[i].state) == currentState && prb(table[i].event) == currentEvent)
        {
            if (prb(table[i].nextState) != STATE_NO_CHANGE)
              currentState = prb(table[i].nextState);
            pStateFunc = (void *)prw(table[i].pStateFunc);
            break;
        }
    }
    
    if (pStateFunc) pStateFunc(); 
}