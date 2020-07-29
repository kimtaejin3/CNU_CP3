#include "QuadEquationProblem.h"
#include<math.h>

// �������ִ� 2�������� �������� 0������ �Ǵ��� �����ش�
Boolean QuadEquationProblem_sendOrderTermCoefficientIsZero(QuadEquationProblem aProblem)
{
	if (FloatValueIsZero(aProblem._equation._c2)){
		return TRUE;
	}
	return FALSE;
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem aProblem)
{
	// �������ִ� 2�������� �Ǻ����� ���� ���������� �Ǵ��� �����ش�
	float determinant = QuadEquationProblem_determinant(aProblem);
	
	if (determinant< 0)return TRUE;
	else return FALSE;
}

float QuadEquationProblem_determinant(QuadEquationProblem aProblem)
{
	//������ �ִ� ������������ �Ǻ����� ���� ����Ͽ� �����ش�.
	float a = aProblem._equation._c2;
	float b = aProblem._equation._c1;
	float c = aProblem._equation._c0;

	float determinant = b * b - 4 * a * c;
	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem aProblem)
{ //������ �ִ� ������������ Ǯ�� �� ����� �����ش�,.
	Solution solution;


	double determinant = QuadEquationProblem_determinant(aProblem);//overflow�� �������� �ظ� double�� ����.
	//��ü���� ���� ��Ű�� �ʿ��� ��������� �ʿ��ϸ� �ڽŵ� ����.
	double sqrtDeterminant = sqrt(determinant);//math�� �ݵ�� include

	
	solution._root1 = (-aProblem._equation._c1 + sqrtDeterminant)/ (2.0 * aProblem._equation._c2);
	if (DoubleValueIsZero(solution._root1) && (2.0 * aProblem._equation._c2) < 0) {
		solution._root1 *= -1;
	}
	solution._root2 = (-aProblem._equation._c1-sqrtDeterminant)/ (2.0 * aProblem._equation._c2);

	return solution;
}
