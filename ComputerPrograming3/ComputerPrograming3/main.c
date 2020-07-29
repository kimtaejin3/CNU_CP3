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
		AppView_in_linearEquation(&c0, &c1);//������������ ����� �Է¹���.
		if (FloatValueIsZero(c1))//�������� ����� 0�̸�
		{
			if (FloatValueIsZero(c0)&&c1!=ZEROFLOAT)//�˸��� ǥ���� �ƴ����� c1�� 0.0���� �ƴ��� ������ �ʿ䰡 �ִ�.
			{
				AppView_out_ToSmall_Or_ToLarge(c0,c1);
				root = LinearEquation_solve(c0, c1);//������������ Ǭ��
				AppView_out_root(root);//������������ �ظ� ����Ѵ�
			}
			else
			{
				AppView_out_msg_firstOrderTermCoefficientlsZero();
				//�������� ����� 0�̶�� �޼����� ����Ѵ�
			}
		}
		else
		{
			AppView_out_linearEquation(c0, c1);//�Է¹��� ���������� ���
			root = LinearEquation_solve(c0, c1);//������������ Ǭ��
			AppView_out_root(root);//������������ �ظ� ����Ѵ�.
		}
		solvingRequested = AppView_in_solvingRequested();
	}
	AppView_out_msg_endSolvingLinearEquation();
}

double LinearEquation_solve(float c0, float c1)// MAXFLOAT�� ��ȯ �� float©�� ���, �������� double�� �ٲ�.	
{				
	double mul = (double)c0 * (double)c1;

	if (FloatValueIsZero(c1))
	{
		if (FloatValueIsZero(c0)&&c1!=ZEROFLOAT)//�� ���� ��ΰ�  0���� ������ ��. �Ǽ�!=0�� �˸��� ǥ���� �ƴ����� 0���� ���� ���� ����,
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
