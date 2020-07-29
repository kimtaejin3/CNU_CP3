#include "QuadEquationProblem.h"
#include<math.h>

// 가지고있는 2차방정식 이차항이 0인지를 판단해 돌려준다
Boolean QuadEquationProblem_sendOrderTermCoefficientIsZero(QuadEquationProblem aProblem)
{
	if (FloatValueIsZero(aProblem._equation._c2)) {
		return TRUE;
	}
	return FALSE;
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem *_this)
{
	// 가지고있는 2차방정식 판별식의 값이 음수인지를 판단해 돌려준다
	float determinant = QuadEquationProblem_determinant(_this);

	if (determinant < 0)return TRUE;
	else return FALSE;
}

float QuadEquationProblem_determinant(QuadEquationProblem* _this)
{
	//가지고 있는 이차방정식의 판별식의 값을 계산하여 돌려준다.
	float a = _this->_equation._c2;
	float b = _this->_equation._c1;
	float c = _this->_equation._c0;

	float determinant = b * b - 4 * a * c;
	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem *_this)
{ //가지고 있는 이차방정식을 풀어 그 결과를 돌려준다,.
	Solution solution;


	double determinant = QuadEquationProblem_determinant(_this);//overflow를 막기위해 해를 double로 받음.
	//객체에게 일을 시키는 쪽에서 사용하지만 필요하면 자신도 쓴다.
	double sqrtDeterminant = sqrt(determinant);//math를 반드시 include


	solution._root1 = (-_this->_equation._c1 + sqrtDeterminant) / (2.0 * _this->_equation._c2);
	if (DoubleValueIsZero(solution._root1) && (2.0 * _this->_equation._c2) < 0) {
		solution._root1 *= -1;
	}
	solution._root2 = (-_this->_equation._c1 - sqrtDeterminant) / (2.0 * _this->_equation._c2);

	return solution;
}

void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation)
{
	_this->_equation = anEquation;
}