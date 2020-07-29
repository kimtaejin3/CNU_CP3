#include<stdio.h>
#include "AppView.h"

int AppView_in_order(void)
{
	int number;
	printf("\n?마방진 차수를 입력하시오:");
	scanf_s("%d", &number);
	
	return number;
}

void AppView_out(char* aMessage)
{
	printf("%s", aMessage);
}