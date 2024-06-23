#ifndef __CAL_H__
#define __CAL_H__
#include "reg51.h"
#include "lcd.h"
#include "keypad.h"
#include "reg51.h"
#include <stdio.h>
void operationScan(void);
void errorDisp(void);
char syntaxCheck(long int*num,char*h,char first_op);
char check(void);
void divide_complete(void);
void ansDesplay(char oper,long int*ans);
void lcd_clear(void);
#endif