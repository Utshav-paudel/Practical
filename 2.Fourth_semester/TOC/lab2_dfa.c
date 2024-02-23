// Lab2 : Design a DFA 01011                    
// Date : 2080/10/11
//TOC
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int initial_state =1, len,current_state=2;
char a,b,str[10];
printf("Enter your string :");
scanf("%s",&str);
len = strlen(str);
if (len==5)
{
	if (initial_state==1 && str[0]=='0')
	{
		current_state= 2;
		
	}
	if(current_state==2 && str[1] =='1')
	{
		current_state=3;
	}
	if(current_state==3 && str[2] == '0')
	{
		current_state=4;
	}
	if(current_state==4 && str[3] == '1')
	{
		current_state=5;
	}
	if(current_state==5 && str[4] == '1')
	{
		printf("String is accepted");
	}
	else
	{
		printf("String is rejected");
	}
}
else
{
	printf("Enter correct string having length 5");
	
}
}
