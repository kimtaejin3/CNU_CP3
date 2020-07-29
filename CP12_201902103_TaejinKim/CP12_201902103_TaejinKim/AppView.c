#define _CRT_SECURE_NO_WARNINGS
#include"AppView.h"
#include<stdio.h>

void AppView_out(char* aString)
{
	printf("%s", aString);
}

void AppView_showToken(int aToken) {
	printf("%d ", aToken);
}

void AppView_showOperatorToken(char aToken) 
{
	printf("%c ", aToken);
}

Boolean AppView_in_InfixExpression(char* aExpression) {
	AppView_out("\n? Infix 수식을 입력하시오: ");
	scanf("%s", aExpression);
	if (aExpression[0] == '@') {
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

void AppView_out_resultForPostfix(char* postfixExpression)
{
	printf(">> 변환된 Postfix: %s", postfixExpression);
}

void AppView_out_evaluatedValue(int anEvaluateValue) {
	printf("계산값 : %d\n", anEvaluateValue);
}

void AppView_out_startingMessage()
{
	AppView_out("<<< Infix 수식 계산을 시작합니다 >>>\n");
}

void AppView_out_endingMessage() {
	AppView_out("\n<<< Infix 수식 계산을 종료합니다 >>>\n");
}

void AppView_out_startingInfixToPostfix() {
	AppView_out("> Infix를 Postfix로 변환합니다:\n");
}

void AppView_out_startingPostfix()
{
	AppView_out("> Postfix 수식을 계산합니다:\n");
}

void  AppView_out_postfixEvaluationErrorMessage(PostfixError aPostfixError)
{
	if (aPostfixError == PostfixError_ExpressionTooLong) {
		printf(ErrorMsg_ExpressionTooLong);
	}
	else if (aPostfixError == PostfixError_OperandsTooMany) {
		printf(ErrorMsg_OperadsTooMany);
	}
	else if (aPostfixError == PostfixError_OperandsTooFew) {
		printf(ErrorMsg_OperandsTooFew);
	}
	else if (aPostfixError == PostfixError_UnknownOperator) {
		printf(ErrorMsg_UnknownOperator);
	}
	else if (aPostfixError == PostfixError_DivideByZero) {
		printf(ErrorMsg_DivideByZero);
	}

}

