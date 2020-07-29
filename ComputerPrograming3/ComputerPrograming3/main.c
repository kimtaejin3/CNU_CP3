#include<math.h>
#include "AppView.h"
#include "Common.h"

double LinearEquation_solve(float c0, float c1);

void main()
{
	Boolean solvingRequested;
	float c0, c1;
	double root;
	
	AppView_out_msg_startSolvingLinearEquation();
	solvingRequested = AppView_in_solvingRequested();
	while (solvingRequested) {
		AppView_in_linearEquation(&c0, &c1);//일차방정식의 계수를 입력받음.
		if (FloatValueIsZero(c1))//일차항의 계수가 0이면
		{
			if (FloatValueIsZero(c0)&&c1!=ZEROFLOAT)//알맞은 표현은 아니지만 c1이 0.0임이 아님을 구별할 필요가 있다.
			{
				AppView_out_ToSmall_Or_ToLarge(c0,c1);
				root = LinearEquation_solve(c0, c1);//일차방정식을 푼다
				AppView_out_root(root);//일차방정식의 해를 출력한다
			}
			else
			{
				AppView_out_msg_firstOrderTermCoefficientlsZero();
				//일차항의 계수가 0이라는 메세지를 출력한다
			}
		}
		else
		{
			AppView_out_linearEquation(c0, c1);//입력받은 일차방정식 출력
			root = LinearEquation_solve(c0, c1);//일차방정식을 푼다
			AppView_out_root(root);//일차방정식의 해를 출력한다.
		}
		solvingRequested = AppView_in_solvingRequested();
	}
	AppView_out_msg_endSolvingLinearEquation();
}

double LinearEquation_solve(float c0, float c1)// MAXFLOAT을 반환 시 float짤림 경고, 반한형을 double로 바꿈.	
{				
	double mul = (double)c0 * (double)c1;

	if (FloatValueIsZero(c1))
	{
		if (FloatValueIsZero(c0)&&c1!=ZEROFLOAT)//두 변수 모두가  0으로 판정될 시. 실수!=0은 알맞은 표현이 아니지만 0으로 나눌 수는 없다,
		{
			return(-c0) / c1;
		}
		if (mul >= 0.0) {
			return -MAXFLOAT;
		}
		else {
			return +MAXFLOAT;
		}
	}
	else
	{
		return (-c0) / c1;
	}
}
