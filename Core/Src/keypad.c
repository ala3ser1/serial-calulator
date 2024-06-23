/*
 * keypad.c
 *
 *  Created on: Apr 23, 2024
 *      Author: melaa
 */

#include"keypad.h"
unsigned char keypadRead(void)
{
	char ret=0;
	ret=HAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD4);
	ret=(ret<<1)|HAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD5);
	ret=(ret<<1)|HAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD6);
	ret=(ret<<1)|HAL_GPIO_ReadPin(KEYPAD_PORT, KEYPAD7);
	return ret;
}


static const unsigned char keypad[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{' ','0','=','+'}};
unsigned char ReadKey(void)
{
	unsigned char index;
	unsigned char index2,i=0;
	while(keypadRead()!=0xf);
	while(1)
	{


		HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD0, 0);
		if(keypadRead()!=0xf)
		{
			 HAL_Delay(15);
			 if(keypadRead()!=0xf)
			 {
				 index=0;
				 break;
			 }
		}
		else{
			HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD0, 1);
			HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD1, 0);
			if(keypadRead()!=0xf)
				{
				HAL_Delay(15);
						 if(keypadRead()!=0xf)
						 {
							 index=1;
							 break;
						 }
				}
				else{
					HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD1, 1);
					HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD2, 0);
					if(keypadRead()!=0xf)
						{
						HAL_Delay(15);
								 if(keypadRead()!=0xf)
								 {
									 index=2;
									 break;
								 }
						}
						else{
							HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD2, 1);
							HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD3, 0);
							if(keypadRead()!=0xf)
								{
								HAL_Delay(15);
										 if(keypadRead()!=0xf)
										 {
											 index=3;
											 break;
										 }
								}
								else{

									HAL_GPIO_WritePin(KEYPAD_PORT, KEYPAD3, 1);
								}

						}
				}
		}
	}

	index2=keypadRead();
	while((index2>>i)&1)
	{
		i++;
	}
	return keypad[index][3-i];

}
