#ifndef __lcd_h__
#define __lcd_h__
#include "reg51.h"

/** LCD COMMANDS**/
#define CLEAR_SCREAN                 0x01
#define SET_8_BIT_1_LINE             0x30
#define SET_8_BIT_2_LINE             0x38
#define SET_4_BIT_1_LINE             0x20
#define SET_4_BIT_2_LINE             0x28
#define ENTRY_MODE								   0x06
#define DISPLAY_OFF__CURSOR_OFF 		 0x08
#define DISPLAY_ON__CURSOR_ON 			 0x0E
#define DISPLAY_ON__CURSOR_OFF 		   0x0C
#define DISPLAY_ON__CURSOR_BLINKING  0x0F
#define SHIFT_ENTIRE_LEFT 				   0x18
#define SHIFT_ENTIRE_RIGHT           0x1c
#define MOVE_CURSOR_LEFT             0x10
#define MOVE_CURSOR_RIGHT            0x14
#define FORCE_TO_FIRST_ROW           0x80
#define FORCE_TO_SECOND_ROW          0xC0

//********************************************//
#define INSTRUCTION_PIN P2^1
#define ENABLE_PIN P2^0
#define LCD_PORT P0
sbit RS=INSTRUCTION_PIN;
sbit E=ENABLE_PIN;
void lcdDelay(void);
void lcdCommand(char command);
void lcdData(char dataa);
void lcdDesplay(char*letter);
void lcdInti(void);
void lcdDisplayNum(long int num);
void num_package(long int num);

#endif