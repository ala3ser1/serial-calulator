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
		x=readKey();
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
		x=readKey();
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
void divide_complete(void)
{
	int print;
	char i=0;
	long int rem=num1%num2;
	rem*=10;
	lcdData('.');
	for(i=0;i<7&&rem!=0;i++)
	{
		print=rem/num2;
		lcdData((print)+'0');
		if(print==0)
		{
			rem*=10;
		}
		else{
		rem=rem%num2;
		}
		
		
	}
	
	
}
void ansDesplay(char oper,long int*ans)
{
	
	
		switch (oper)
			{
				case '=':
					lcdCommand(FORCE_TO_SECOND_ROW);
				*ans =num1;
					lcdDisplayNum(*ans);
				break;
				case '-':
					lcdCommand(FORCE_TO_SECOND_ROW);
				*ans=num1-num2;
					lcdDisplayNum(*ans);
				break;
				case '*':
					lcdCommand(FORCE_TO_SECOND_ROW);
				*ans=num1*num2;
					lcdDisplayNum(*ans);
				break;
				case '+':
				lcdCommand(FORCE_TO_SECOND_ROW);
				*ans =num1+num2;
				lcdDisplayNum(*ans);
				break;
				case '/':
				lcdCommand(FORCE_TO_SECOND_ROW);
				*ans =num1/num2;
				lcdDisplayNum(*ans);
				if(num1%num2)
				{
					divide_complete();
				}
				break;
			}
	
	
}
