#include "Common.h"
#include "AppView.h"
#include "QuadEquationProblem.h"

int main()
{
	QuadEquationProblem qeProblem; //객체 qeProblem생성
	Boolean solvingIsRequested;
	QuadEquation equation;
	Solution solution;

	AppView_out_msg_startSolvingQuadEquation();//시작메세지출력
	solvingIsRequested = AppView_in_solvingIsRequested();//문제풀이여부를 묻고 응답을 얻는다
	while (solvingIsRequested) {
		AppView_in_quadEquation(&equation._c0,&equation._c1, &equation._c2);
		AppView_out_quadEquation(equation._c0, equation._c1, equation._c2);
		qeProblem._equation = equation;//어쩔수없는 상황

		if (QuadEquationProblem_sendOrderTermCoefficientIsZero(qeProblem))
		{
			AppView_out_msg_secondOrderTermCoefficientIsZero();
		}
		else
		{
			if (QuadEquationProblem_determinantIsNegative(qeProblem))
			{
				float determinant = QuadEquationProblem_determinant(qeProblem);
				AppView_out_msg_determinantIsNegative(determinant);
			}
			else
			{
				solution = QuadEquationProblem_solve(qeProblem);
				AppView_out_solution(solution._root1, solution._root2);
			}
		}
		solvingIsRequested = AppView_in_solvingIsRequested();//문제풀이 여부를 묻고 응답을 얻는다
	}
	AppView_out_msg_endSolvingQuadEquation();//종료메세지출력
	return 0;
}