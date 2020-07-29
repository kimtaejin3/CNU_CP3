#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include "Common.h"
#include<stdio.h>
#include<math.h>

void AppView_out_msg_startSolvingLinearEquation()
{
	printf("<<< 일차방정식의 풀이를 시작합니다 >>>\n");
}

void AppView_out_msg_endSolvingLinearEquation()
{
	printf("\n<<< 일차방정식의 풀이를 종료합니다 >>>\n");
}

Boolean AppView_in_solvingRequested()
{
	char answer,p;
	printf("\n? 방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시요: ");
	char inputLine[255];
	p=scanf("%s", inputLine);
	answer = inputLine[0];
	return (answer == 'y');
}

void AppView_in_linearEquation(float* p_c0, float* p_c1)
{
	char p;
	printf("? 1차항의 계수를 입력하시오: ");
	p=scanf("%f", p_c1);
	printf("? 상수항의 계수를 입력하시요: ");
	p=scanf("%f", p_c0);
}

void AppView_out_linearEquation(float c0, float c1)
{
	
	printf(">주어진 방정식: (%f)x + (%f) = 0 \n", c1, c0);
}

void AppView_out_root(double root)
{
	printf("> 방정식의 해는 다음과 같습니다: \n");
	printf("x = %f\n", root);
}

void AppView_out_msg_firstOrderTermCoefficientlsZero()
{
	printf("[오류] 1 차항의 계수가 0이어서, 방정식을 풀 수 없습니다.\n");
}

void AppView_out_ToSmall_Or_ToLarge()
{
	printf("> 주어진 상수들이 *모두* 0과 가까워 프로그램상 방정식을 제대로 나타낼 수 없습니다.\n");
}