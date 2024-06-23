#include<reg51.h>
#include<LCD.h>
 char count=0;
unsigned char arr[15]={0};
void Serial(void)
{
	
	unsigned char letter=5;
	count =0;
	while(letter!='b')
	{
		while(RI==0);
		RI=0;
		letter=SBUF;
		arr[count++]=letter;
}

}
void delay(void)
{
	int i;
	for( i=0;i<500;i++);
}

void main()
{unsigned char dot,flag;
	char i;
	lcdInti();
	lcdDesplay("serial result");
	TMOD=0x20;
	TH1=-3;
	TR1=1;
	SCON=0x50;

	while(1)
	{ 
   	Serial();
		lcdCommand(FORCE_TO_SECOND_ROW);
		lcdDesplay("                 ");
		lcdCommand(FORCE_TO_SECOND_ROW);
		count--;
		
		for(dot=0;dot<count;dot++)
			{
				if(arr[dot]=='.')
				{
					flag=1;
					break;
				}
				
			}
			if(flag)
			{
				for(i=dot-1;i>=0;i--)
				{
					lcdData(arr[i]);
					
				}
				for(i=dot;i<count;i++)
				{
					lcdData(arr[i]);
				}
				
			}
			else
			{
				for(i=count-1;i>=0;i--)
				{
					lcdData(arr[i]);
				}
			}
			
		flag=0;
		
		

		
		
	}
	
	
	
}
	
