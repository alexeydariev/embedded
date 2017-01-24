
#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include <avr/pgmspace.h>
#include "list_event.h"
#include "interface.h"

#define SIZE_BUF 16       //вместимость буфера/очереди событий

void ES_Init(void);                       //инициализация
unsigned char ES_GetEvent(void);           //взять код события  
void ES_PlaceEvent(unsigned char event);   //разместить событие
void ES_Dispatch(unsigned char event);     //вызов диспетчера

#endif // EVENT_SYSTEM_H