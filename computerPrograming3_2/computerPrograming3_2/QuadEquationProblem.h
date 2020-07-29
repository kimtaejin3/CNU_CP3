#include "Common.h"

typedef struct {
	QuadEquation _equation;
}QuadEquationProblem;

//QuadEquatioProblem�� ����� �Լ��̴�.

Boolean QuadEquationProblem_sendOrderTermCoefficientIsZero(QuadEquationProblem aProblem);

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem);

float QuadEquationProblem_determinant(QuadEquationProblem aProblem);

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem);