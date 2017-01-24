#ifndef INTERFACE_H
#define INTERFACE_H

#include <avr/io.h>
#include "lcd_lib.h"
#include "bcd.h"

void GUI_General(void);
void GUI_SelectHour(void);
void GUI_SelectMinute(void);
void GUI_IncHour(void);
void GUI_DecHour(void);
void GUI_IncMinute(void);
void GUI_DecMinute(void);
void GUI_SetTime(void);
void GUI_ChangeTime(void);

#endif //INTERFACE_H