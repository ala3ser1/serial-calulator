/*
 * lcd.h
 *
 *  Created on: Apr 23, 2024
 *      Author: melaa
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
typedef union{
	unsigned char byte;
	struct{
		unsigned char b0:1;
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
	};
}BYTE_T;

#define GET_BYTE(x,y) (((x)>>(y))&(1))

#define CLEAR_SCREAN                 0x01
#define SET_8_BIT_1_LINE             0x30
#define SET_8_BIT_2_LINE             0x38
#define SET_4_BIT_1_LINE             0x20
#define SET_4_BIT_2_LINE             0x28
#define ENTRY_MODE				     0x06
#define DISPLAY_OFF__CURSOR_OFF      0x08
#define DISPLAY_ON__CURSOR_ON 		 0x0E
#define DISPLAY_ON__CURSOR_OFF 		 0x0C
#define DISPLAY_ON__CURSOR_BLINKING  0x0F
#define SHIFT_ENTIRE_LEFT 		     0x18
#define SHIFT_ENTIRE_RIGHT           0x1c
#define MOVE_CURSOR_LEFT             0x10
#define MOVE_CURSOR_RIGHT            0x14
#define FORCE_TO_FIRST_ROW           0x80
#define FORCE_TO_SECOND_ROW          0xC0

#define LCD0 GPIO_PIN_0
#define LCD1 GPIO_PIN_1
#define LCD2 GPIO_PIN_2
#define LCD3 GPIO_PIN_3
#define LCD4 GPIO_PIN_4
#define LCD5 GPIO_PIN_5
#define LCD6 GPIO_PIN_6
#define LCD7 GPIO_PIN_7
#define E    GPIO_PIN_8
#define RS   GPIO_PIN_9
#define LCD_PORT GPIOA
void Lcd_PortWrite(unsigned char data);
void lcdCommand(unsigned char command);
void lcdData(unsigned char data);
void lcdInti(void);
void lcdDesplay(char*letter);
void lcdDisplayNum(long int num);


#endif /* INC_LCD_H_ */
