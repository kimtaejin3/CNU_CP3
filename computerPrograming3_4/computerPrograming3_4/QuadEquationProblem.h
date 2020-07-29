#include "Common.h"

typedef struct {
	QuadEquation _equation;
}QuadEquationProblem;

//QuadEquatioProblem�� ����� �Լ��̴�.

Boolean QuadEquationProblem_sendOrderTermCoefficientIsZero(QuadEquationProblem aProblem);

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem *_this);

float QuadEquationProblem_determinant(QuadEquationProblem *_this);

Solution QuadEquationProblem_solve(QuadEquationProblem *_this);

void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation);