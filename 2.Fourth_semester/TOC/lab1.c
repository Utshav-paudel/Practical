//TOC
//Labno:1                     Date: 2080/09/23

// Design a DFA for accepting language aab in C program
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
if (len==3)
{
	if (initial_state==1 && str[0]=='a')
	{
		current_state= 2;
		
	}
	if(current_state==2 && str[1] =='a')
	{
		current_state=3;
	}
	if(current_state==3 && str[2] == 'b')
	{
		current_state=4;
		printf("String is accepted");
	}
	else
	{
		printf("String is rejected");
	}
}
else
{
	printf("Enter correct string having length 3");
	
}
}
