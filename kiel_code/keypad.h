#ifndef __KEYPAD_H__
#define __KEYPAD_H__
#include "reg51.h"
void keypadDebouncd(void);
unsigned char readKey(void);
#endif