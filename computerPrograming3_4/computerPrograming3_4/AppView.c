#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Common.h"
#include "AppView.h"

void AppView_out_msg_startSolvingQuadEquation()
{
	printf("<< 이차방정식 풀이를 시작합니다 >>\n");
}

void AppView_out_msg_endSolvingQuadEquation()
{
	printf("<< 이차방정식 풀이를 종료합니다 >>\n");
}

Boolean AppView_in_solvingIsRequested()
{
	char inputLine[255];
	char answer;
	printf("\n? 방정식을 풀려면 'y', 풀이를 종료하려면 아무거나 치시오: ");
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
	printf("? 2차항의 계수를 입력하시오: ");
	p = scanf("%f", p_c2);

	printf("? 1차항의 계수를 입력하시오: ");
	p = scanf("%f", p_c1);

	printf("? 상수항의 계수를 입력하시오: ");
	p = scanf("%f", p_c0);
}

void AppView_out_quadEquation(float c0, float c1, float c2)
{
	Boolean aNonZeroTermDoesExist = FALSE;
	if (!FloatValueIsZero(c2)) {   //계수가 0인 항은 출력하지 않는다.
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x*x", c2);
	}
	if (!FloatValueIsZero(c1))//계수가 0인 항은 출력하지 않는다.
	{
		if (aNonZeroTermDoesExist)
		{
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x", c1);
	}
	if (!FloatValueIsZero(c0)) {//계수가 0인 항은 출력하지 않는다.

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
	printf("[오류] 이차항의 계수가 0 이어서, 이차방정식이 아닙니다.\n");
}

void AppView_out_msg_determinantIsNegative(float determinant)
{
	printf("> 판별식의 값이 음수이어서, 해가 존재하지 않습니다.\n");
	printf("- 판별식의 값: %f\n", determinant);
}

void AppView_out_solution(double root1, double root2)
{
	printf("방정식의 해는 다음과 같습니다.\n");
	printf("x1 = %lf\n", root1);
	printf("x2 = %lf\n", root2);
}
