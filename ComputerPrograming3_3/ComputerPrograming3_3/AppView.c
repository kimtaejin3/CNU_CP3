#include<stdio.h>
#include "AppView.h"

int AppView_in_order(void)
{
	int number;
	printf("\n?������ ������ �Է��Ͻÿ�:");
	scanf_s("%d", &number);
	
	return number;
}

void AppView_out(char* aMessage)
{
	printf("%s", aMessage);
}