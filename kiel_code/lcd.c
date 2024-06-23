
#include "lcd.h"
char i=0;
char num_arr[10];
void lcdDelay(void)
{
    unsigned int j;
    for(j=0; j<10; j++);
}
void lcdCommand(char command)
{
    LCD_PORT=command;
    RS=0;
    E=1;
    E=0;
    lcdDelay();
}
void lcdData(char dataa)
{
    LCD_PORT=dataa;
    RS=1;
    E=1;
    E=0;
    lcdDelay();
}

void lcdInti(void)
{
	int i;
    lcdCommand(DISPLAY_ON__CURSOR_ON );
    lcdCommand(SET_8_BIT_2_LINE);

}



void lcdDesplay(char*letter)
{
    char i=0;
    while(letter[i])
    {
        lcdData(letter[i]);
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
