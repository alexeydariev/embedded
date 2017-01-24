#include "interface.h"

static unsigned char hours = 0;
static unsigned char minutes = 0;
static unsigned char seconds = 0;

void GUI_General(void)
{
  LCD_Clear();
  LCD_Goto(1, 0);
  LCD_SendString("clock");
  LCD_Goto(1, 1);
  BCD_2Lcd(hours);
  if (seconds&1){
    LCD_WriteData(' ');
  }
  else{
    LCD_WriteData(':');
  }
  BCD_2Lcd(minutes);
  
  seconds = 0;
}

void GUI_SelectHour(void)
{
  LCD_Goto(0, 1);
  LCD_WriteData('<');
  BCD_2Lcd(hours);
  LCD_WriteData('>');
}

void GUI_SelectMinute(void)
{
  LCD_Goto(0, 1);
  LCD_WriteData(' ');
  BCD_2Lcd(hours);
  LCD_WriteData('<');
  BCD_2Lcd(minutes);
  LCD_WriteData('>');
}

void GUI_IncHour(void)
{
  if (hours == 23) {hours = 0;}
  else {hours++;}
  LCD_Goto(1, 1);  
  BCD_2Lcd(hours);
}

void GUI_DecHour(void)
{
  if (hours == 0) {hours = 23;}
  else {hours--;}
  LCD_Goto(1, 1);  
  BCD_2Lcd(hours);
}

void GUI_IncMinute(void)
{
  if (minutes == 59) {minutes = 0;}
  else {minutes++;}
  LCD_Goto(4, 1);  
  BCD_2Lcd(minutes);
}

void GUI_DecMinute(void)
{
  if (minutes == 0) {minutes = 59;}
  else {minutes--;}
  LCD_Goto(4, 1);  
  BCD_2Lcd(minutes);
}

void GUI_SetTime(void)
{
  LCD_Goto(4, 1);  
  BCD_2Lcd(minutes);
}

void GUI_ChangeTime(void)
{
  seconds++;
  if (seconds == 60){
    seconds = 0;
    minutes++;
    if (minutes == 60){
      minutes = 0;
      hours++;
      if (hours == 24){
        hours = 0;
      }
    }
  }
  
  LCD_Goto(1, 1);
  BCD_2Lcd(hours);
  if (seconds&1){
    LCD_WriteData(' ');
  }
  else{
    LCD_WriteData(':');
  }
  BCD_2Lcd(minutes);
}