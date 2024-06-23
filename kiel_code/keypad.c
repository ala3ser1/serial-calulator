#include"keypad.h"
unsigned char keypad[4][4]= {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{' ','0','=','+'}};

#define KEYPAD P1
void keypadDebouncd(void)
{
    int i;
    for(i=2500; i>0; i--);

}
unsigned char readKey(void)
{
    char flag=0,i,input;
    KEYPAD=0xff;
    while(KEYPAD!=0xff);
    while(!flag)
    {

        for(i=0; (i<4)&&(!flag); i++,KEYPAD=0xff)
        {
            KEYPAD=KEYPAD&(~(1<<(7-i)));
            input=KEYPAD&0x0f;
            if(input!=0x0f)
            {
                keypadDebouncd();
                input=KEYPAD&0x0f;
                if(input!=0x0f)
                {
                    while((KEYPAD&0x0f)!=0x0f);
                    keypadDebouncd();
                    flag=1;
                }
            }

        }


    }
    flag=0;
    while((input>>flag)&1)
    {
        flag++;
    }
    return keypad[i-1][flag];

}
