#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include "Common.h"
#include<stdio.h>
#include<math.h>

void AppView_out_msg_startSolvingLinearEquation()
{
	printf("<<< ������������ Ǯ�̸� �����մϴ� >>>\n");
}

void AppView_out_msg_endSolvingLinearEquation()
{
	printf("\n<<< ������������ Ǯ�̸� �����մϴ� >>>\n");
}

Boolean AppView_in_solvingRequested()
{
	char answer,p;
	printf("\n? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");
	char inputLine[255];
	p=scanf("%s", inputLine);
	answer = inputLine[0];
	return (answer == 'y');
}

void AppView_in_linearEquation(float* p_c0, float* p_c1)
{
	char p;
	printf("? 1������ ����� �Է��Ͻÿ�: ");
	p=scanf("%f", p_c1);
	printf("? ������� ����� �Է��Ͻÿ�: ");
	p=scanf("%f", p_c0);
}

void AppView_out_linearEquation(float c0, float c1)
{
	
	printf(">�־��� ������: (%f)x + (%f) = 0 \n", c1, c0);
}

void AppView_out_root(double root)
{
	printf("> �������� �ش� ������ �����ϴ�: \n");
	printf("x = %f\n", root);
}

void AppView_out_msg_firstOrderTermCoefficientlsZero()
{
	printf("[����] 1 ������ ����� 0�̾, �������� Ǯ �� �����ϴ�.\n");
}

void AppView_out_ToSmall_Or_ToLarge()
{
	printf("> �־��� ������� *���* 0�� ����� ���α׷��� �������� ����� ��Ÿ�� �� �����ϴ�.\n");
}