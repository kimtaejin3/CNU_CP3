#include<stdio.h>
#include "AppView.h"

int AppView_in_order(void)
{
	int number;
	printf("?마방진 차수를 입력하시오:");
	scanf_s("%d", &number);

	return number;
}

void AppView_out(char* aMessage)
{
	printf("%s", aMessage);
}


void AppView_out_executionTime(int anOrder, double anExecutionTime) {
	printf("차수: %2d, 시간: %lf (마이크로초)\n", anOrder, anExecutionTime);
}
