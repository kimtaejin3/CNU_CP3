#include "Common.h"

typedef struct {
	QuadEquation _equation;
}QuadEquationProblem;

//QuadEquatioProblem과 직결된 함수이다.

Boolean QuadEquationProblem_sendOrderTermCoefficientIsZero(QuadEquationProblem aProblem);

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem);

float QuadEquationProblem_determinant(QuadEquationProblem aProblem);

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem);