#define _CRT_SECURE_NO_WARNINGS
#include"AppView.h"


void AppView_out(char* aString)
{
	printf("%s", aString);
}

void AppView_showToken(int aToken) {
	printf("%d ", aToken);
}

Boolean AppView_in_postfixExpression(char* aExpression) {
	AppView_out("\n> ������ �Է��Ͻÿ�: ");
	scanf("%s", aExpression);
	if (aExpression[0]=='$') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void AppView_out_errorInExpression()
{
	printf(">> ���Ŀ� ������ �ֽ��ϴ�.\n");
}

AppView_out_evaluatedValue(int anEvaluateValue) {
	 printf ("��갪 : %d\n", anEvaluateValue) ;
}

void AppView_out_startingMessage()
{
	AppView_out("<<< Postfix ���� ����� �����մϴ� >>>\n");
}

void AppView_out_endingMessage() {
	AppView_out("\n<<< Postfix ���� ����� �����մϴ� >>>\n");
}


