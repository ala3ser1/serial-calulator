/*
 * keypad.h
 *
 *  Created on: Apr 23, 2024
 *      Author: melaa
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include"main.h"
#define KEYPAD0 GPIO_PIN_0
#define KEYPAD1 GPIO_PIN_1
#define KEYPAD2 GPIO_PIN_2
#define KEYPAD3 GPIO_PIN_3
#define KEYPAD4 GPIO_PIN_4
#define KEYPAD5 GPIO_PIN_5
#define KEYPAD6 GPIO_PIN_6
#define KEYPAD7 GPIO_PIN_7
#define KEYPAD_PORT GPIOB
unsigned char keypadRead(void);
unsigned char ReadKey(void);

#endif /* INC_KEYPAD_H_ */
