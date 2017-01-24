
#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include <avr/pgmspace.h>
#include "list_event.h"
#include "interface.h"

#define SIZE_BUF 16       //����������� ������/������� �������

void ES_Init(void);                       //�������������
unsigned char ES_GetEvent(void);           //����� ��� �������  
void ES_PlaceEvent(unsigned char event);   //���������� �������
void ES_Dispatch(unsigned char event);     //����� ����������

#endif // EVENT_SYSTEM_H