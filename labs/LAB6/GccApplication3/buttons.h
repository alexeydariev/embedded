
#ifndef	BUTTONS_h
#define	BUTTONS_h

#include <avr/io.h>
#include "event-system.h"
#include "list_event.h"

//����, � �������� ���������� ������
#define PORT_BUTTON 	PORTB
#define PIN_BUTTON 		PINB
#define DDRX_BUTTON 	DDRB

//������ �������, � ������� ���������� ������
#define DOWN 		4
#define UP			3
#define ENTER 		2

//������� ������ ������ ������ ������ ������������
#define THRESHOLD 5
/**************************************************************************
*   Function name : BUT_Init
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ������������� ������ �����/������
*                   ���������� ������ � ������ main`a
****************************************************************************/
void BUT_Init(void);

/**************************************************************************
*   Function name : BUT_Debrief
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ���������� ������. ���������� ������ �� ����������
*                   ���� ������ ������ � ������� 20 ����������,
*                   �� ����� ������������ � �����
****************************************************************************/
void BUT_Debrief(void);

#endif //BUTTONS_H
