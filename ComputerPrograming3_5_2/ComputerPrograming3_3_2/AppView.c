#include<stdio.h>
#include "AppView.h"

int AppView_in_order(void)
{
	int number;
	printf("?������ ������ �Է��Ͻÿ�:");
	scanf_s("%d", &number);

	return number;
}

void AppView_out(char* aMessage)
{
	printf("%s", aMessage);
}


void AppView_out_executionTime(int anOrder, double anExecutionTime) {
	printf("����: %2d, �ð�: %lf (����ũ����)\n", anOrder, anExecutionTime);
}
