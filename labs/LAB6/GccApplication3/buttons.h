
#ifndef	BUTTONS_h
#define	BUTTONS_h

#include <avr/io.h>
#include "event-system.h"
#include "list_event.h"

//порт, к которому подключены кнопки
#define PORT_BUTTON 	PORTB
#define PIN_BUTTON 		PINB
#define DDRX_BUTTON 	DDRB

//номера выводов, к которым подключены кнопки
#define DOWN 		4
#define UP			3
#define ENTER 		2

//сколько циклов опроса кнопка должна удерживаться
#define THRESHOLD 5
/**************************************************************************
*   Function name : BUT_Init
*   Returns :       нет
*   Parameters :    нет
*   Purpose :       инициализация портов ввода/вывода
*                   вызывается обычно в начале main`a
****************************************************************************/
void BUT_Init(void);

/**************************************************************************
*   Function name : BUT_Debrief
*   Returns :       нет
*   Parameters :    нет
*   Purpose :       опрашивает кнопки. вызывается обычно из прерывания
*                   если кнопка нажата в течении 20 прерываний,
*                   ее номер записывается в буфер
****************************************************************************/
void BUT_Debrief(void);

#endif //BUTTONS_H
