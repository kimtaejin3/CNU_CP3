#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Common.h"
#include "AppView.h"

void AppView_out_msg_startSolvingQuadEquation()
{
	printf("<< ���������� Ǯ�̸� �����մϴ� >>\n");
}

void AppView_out_msg_endSolvingQuadEquation()
{
	printf("<< ���������� Ǯ�̸� �����մϴ� >>\n");
}

Boolean AppView_in_solvingIsRequested()
{
	char inputLine[255];
	char answer;
	printf("\n? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ƹ��ų� ġ�ÿ�: ");
	answer = scanf("%s", inputLine);
	answer = inputLine[0];
	if (answer == 'y')
		return TRUE;
	else
		return FALSE;
}

void AppView_in_quadEquation(float* p_c0, float* p_c1, float* p_c2)
{
	int p;
	printf("? 2������ ����� �Է��Ͻÿ�: ");
	p = scanf("%f", p_c2);

	printf("? 1������ ����� �Է��Ͻÿ�: ");
	p = scanf("%f", p_c1);

	printf("? ������� ����� �Է��Ͻÿ�: ");
	p = scanf("%f", p_c0);
}

void AppView_out_quadEquation(float c0, float c1, float c2)
{
	Boolean aNonZeroTermDoesExist = FALSE;
	if (!FloatValueIsZero(c2)) {   //����� 0�� ���� ������� �ʴ´�.
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x*x", c2);
	}
	if (!FloatValueIsZero(c1))//����� 0�� ���� ������� �ʴ´�.
	{
		if (aNonZeroTermDoesExist)
		{
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x", c1);
	}
	if (!FloatValueIsZero(c0)) {//����� 0�� ���� ������� �ʴ´�.

		if (aNonZeroTermDoesExist)
		{
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)", c0);
	}
	if (!aNonZeroTermDoesExist)
	{
		printf("0");
	}
	printf(" = 0\n");

}

void AppView_out_msg_secondOrderTermCoefficientIsZero()
{
	printf("[����] �������� ����� 0 �̾, ������������ �ƴմϴ�.\n");
}

void AppView_out_msg_determinantIsNegative(float determinant)
{
	printf("> �Ǻ����� ���� �����̾, �ذ� �������� �ʽ��ϴ�.\n");
	printf("- �Ǻ����� ��: %f\n", determinant);
}

void AppView_out_solution(double root1, double root2)
{
	printf("�������� �ش� ������ �����ϴ�.\n");
	printf("x1 = %lf\n", root1);
	printf("x2 = %lf\n", root2);
}
