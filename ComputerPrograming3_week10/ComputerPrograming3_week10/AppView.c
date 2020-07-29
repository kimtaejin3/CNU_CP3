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
	AppView_out("\n> 수식을 입력하시오: ");
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
	printf(">> 수식에 오류가 있습니다.\n");
}

AppView_out_evaluatedValue(int anEvaluateValue) {
	 printf ("계산값 : %d\n", anEvaluateValue) ;
}

void AppView_out_startingMessage()
{
	AppView_out("<<< Postfix 수식 계산을 시작합니다 >>>\n");
}

void AppView_out_endingMessage() {
	AppView_out("\n<<< Postfix 수식 계산을 종료합니다 >>>\n");
}


