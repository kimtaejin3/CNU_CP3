#include "Common.h"
#include "AppView.h"
#include "QuadEquationProblem.h"

int main()
{
	QuadEquationProblem qeProblem; //��ü qeProblem����
	Boolean solvingIsRequested;
	QuadEquation equation;
	Solution solution;

	AppView_out_msg_startSolvingQuadEquation();//���۸޼������
	solvingIsRequested = AppView_in_solvingIsRequested();//����Ǯ�̿��θ� ���� ������ ��´�
	while (solvingIsRequested) {
		AppView_in_quadEquation(&equation._c0,&equation._c1, &equation._c2);
		AppView_out_quadEquation(equation._c0, equation._c1, equation._c2);
		qeProblem._equation = equation;//��¿������ ��Ȳ

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
		solvingIsRequested = AppView_in_solvingIsRequested();//����Ǯ�� ���θ� ���� ������ ��´�
	}
	AppView_out_msg_endSolvingQuadEquation();//����޼������
	return 0;
}