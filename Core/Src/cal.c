/*
 * cal.c
 *
 *  Created on: May 7, 2024
 *      Author: melaa
 */


#include"cal.h"
char reset_flag=0;
long int num1,num2;
char oper;
char op[16];
void operationScan(void)
{
	char i=0;
	char x='1';

	for(i=0;(i<15)&&(x!='=');i++)
	{
		x=ReadKey();
		if(x==' ')
		{
			reset_flag=1;
			break;
		}
		else{
		lcdData(x);
			op[i]=x;
		}
	}

	while(x!='='&&!reset_flag)
	{
		x=ReadKey();
		if(x==' ')
		{
			reset_flag=1;
			break;
		}
		else if(x=='=')
		{
			lcdData('=');
		}
	}


}
void lcd_clear(void)
{

	int i;
	lcdCommand(CLEAR_SCREAN);
	for(i=0;i<300;i++);
}
void errorDisp(void)
{
	lcd_clear();
	lcdDesplay("error");
}

char syntaxCheck(long int*num,char*h,char first_op)
{
	char i=*h;
	long int temp=0;
	if(op[i]=='='||op[i]=='+'||op[i]=='/'||op[i]=='*')
	{

		return 0;
	}
	else if(op[i]=='-')
	{
		if(op[i+1]=='+'||op[i+1]=='*'||op[i+1]=='-'||op[i+1]=='/')
			{
				return 0;
			}
		i++;
		while((op[i]<='9')&&(op[i]>='0'))
		{
			if(!first_op){
			if(op[i+1]=='+'||op[i+1]=='*'||op[i+1]=='-'||op[i+1]=='/')
			{
				return 0;
			}
		}
			temp=(temp*10)+(op[i++]-'0');
		}
		*num=-temp;
	}
	else if((op[i]<='9')&&(op[i]>='0'))
	{

		while((op[i]<='9')&&(op[i]>='0'))
		{
			if(!first_op){
			if(op[i+1]=='+'||op[i+1]=='*'||op[i+1]=='-'||op[i+1]=='/')
			{
				return 0;
			}
		}
			temp=(temp*10)+(op[i]-'0');
			i++;

		}

		*num=temp;

	}
	else{
		return 0;
	}
	*h=i;
	return 1;
}

char check(void)
{
	char i;
	i=0;
	  if(syntaxCheck(&num1,&i,1))
		{
			oper=op[i++];
			if(oper!='='){
			if(syntaxCheck(&num2,&i,0))
				{

				}
				else{
					errorDisp();
					return 0;
				}
				}
			}
			else{

					errorDisp();
					return 0;
				}

		return 1;


}
unsigned char arr[20];
char q=0;
void divide_complete(void)
{
	int print;
	char i=0;
	long int rem=num1%num2;
	rem*=10;
	lcdData('.');
	arr[q++]='.';
	for(i=0;i<7&&rem!=0;i++)
	{
		print=rem/num2;

		if(print==0)
		{
			rem*=10;
		}
		else{
			lcdData((print)+'0');
		   arr[q++]=((char)print)+'0';
		rem=rem%num2;
		}


	}
	arr[q]='b';


}

void ansDesplay(char oper,long int*ans)
{


		switch (oper)
			{
				case '=':
					lcdCommand(FORCE_TO_SECOND_ROW);
				*ans =num1;
					lcdDisplayNum(*ans);
					ansSendSerial(*ans);

				break;
				case '-':
					lcdCommand(FORCE_TO_SECOND_ROW);
				*ans=num1-num2;
					lcdDisplayNum(*ans);
					ansSendSerial(*ans);
				break;
				case '*':
					lcdCommand(FORCE_TO_SECOND_ROW);
				*ans=num1*num2;
					lcdDisplayNum(*ans);
					ansSendSerial(*ans);
				break;
				case '+':
				lcdCommand(FORCE_TO_SECOND_ROW);
				*ans =num1+num2;
				lcdDisplayNum(*ans);
				ansSendSerial(*ans);
				break;
				case '/':
				lcdCommand(FORCE_TO_SECOND_ROW);
				if(num2==0)
				{
					errorDisp();
				}
				else
				{
					*ans =num1/num2;
					lcdDisplayNum(*ans);
					ansSendSerial(*ans);
					if(num1%num2)
					{
						divide_complete();
					}
				}

				break;
			}


}
void ansSendSerial(long int num)
{
	char flag=0;
    q=0;
	if(num<0)
	{
		flag=1;
		num=num*-1;
	}
	while(num)
	{
		arr[q++]=(num%10)+'0';
		num=num/10;
	}
	if(flag)
	{
		arr[q++]='-';
	}
    arr[q]='b';
}
