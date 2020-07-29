#include "QuadEquationProblem.h"
#include<math.h>

// �������ִ� 2�������� �������� 0������ �Ǵ��� �����ش�
Boolean QuadEquationProblem_sendOrderTermCoefficientIsZero(QuadEquationProblem aProblem)
{
	if (FloatValueIsZero(aProblem._equation._c2)) {
		return TRUE;
	}
	return FALSE;
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem *_this)
{
	// �������ִ� 2�������� �Ǻ����� ���� ���������� �Ǵ��� �����ش�
	float determinant = QuadEquationProblem_determinant(_this);

	if (determinant < 0)return TRUE;
	else return FALSE;
}

float QuadEquationProblem_determinant(QuadEquationProblem* _this)
{
	//������ �ִ� ������������ �Ǻ����� ���� ����Ͽ� �����ش�.
	float a = _this->_equation._c2;
	float b = _this->_equation._c1;
	float c = _this->_equation._c0;

	float determinant = b * b - 4 * a * c;
	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem *_this)
{ //������ �ִ� ������������ Ǯ�� �� ����� �����ش�,.
	Solution solution;


	double determinant = QuadEquationProblem_determinant(_this);//overflow�� �������� �ظ� double�� ����.
	//��ü���� ���� ��Ű�� �ʿ��� ��������� �ʿ��ϸ� �ڽŵ� ����.
	double sqrtDeterminant = sqrt(determinant);//math�� �ݵ�� include


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