/*
 * lcd.c
 *
 *  Created on: Apr 23, 2024
 *      Author: melaa
 */
#include"main.h"
#include"lcd.h"
void Lcd_PortWrite(unsigned char data)
{
	HAL_GPIO_WritePin(LCD_PORT,LCD0, GET_BYTE(data,0));
	HAL_GPIO_WritePin(LCD_PORT,LCD1, GET_BYTE(data,1));
	HAL_GPIO_WritePin(LCD_PORT,LCD2, GET_BYTE(data,2));
	HAL_GPIO_WritePin(LCD_PORT,LCD3, GET_BYTE(data,3));
	HAL_GPIO_WritePin(LCD_PORT,LCD4, GET_BYTE(data,4));
	HAL_GPIO_WritePin(LCD_PORT,LCD5, GET_BYTE(data,5));
	HAL_GPIO_WritePin(LCD_PORT,LCD6, GET_BYTE(data,6));
	HAL_GPIO_WritePin(LCD_PORT,LCD7, GET_BYTE(data,7));
}
void lcdCommand(unsigned char command)
{
	Lcd_PortWrite(command);
	HAL_GPIO_WritePin(LCD_PORT,RS,0);
	HAL_GPIO_WritePin(LCD_PORT,E,1);
	//HAL_Delay(10);
	HAL_GPIO_WritePin(LCD_PORT,E,0);
	HAL_Delay(1);
}
void lcdData(unsigned char data)
{
	Lcd_PortWrite(data);
	HAL_GPIO_WritePin(LCD_PORT,RS,1);
	HAL_GPIO_WritePin(LCD_PORT,E,1);
		//HAL_Delay(10);
	HAL_GPIO_WritePin(LCD_PORT,E,0);
	HAL_Delay(1);
}
void lcdInti(void)
{
	lcdCommand(DISPLAY_ON__CURSOR_ON );
	lcdCommand(SET_8_BIT_2_LINE);

}
void lcdDesplay(char*letter)
{
	unsigned char i=0;
	while(letter[i])
	{
		lcdData(letter[i]);
		i++;
	}

}
char i=0;
char num_arr[10];
void num_package(long int num)
{
    i=0;
    while(num)
    {
        num_arr[i]=(num%10)+'0';
        num=num/10;
        i++;
    }
}

void lcdDisplayNum(long int num)
{
    if(num==0)
    {
        lcdData('0');
    }
    else
    {
        if((num>>31)&1)
        {
            lcdData('-');
            num=num*-1;
            num_package(num);

            while(i>0)
            {
                lcdData(num_arr[--i]);

            }

        }
        else
        {
            num_package(num);
            while(i>0)
            {
                lcdData(num_arr[--i]);
            }
        }

    }


}
