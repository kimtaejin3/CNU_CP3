#include"Common.h"
#include"MessageKOR_PostfixError.h"

void AppView_out(char* aString);

void AppView_showToken(int aToken);

void AppView_out_startingMessage();

void AppView_out_endingMessage();

void AppView_out_errorInExpression();

void AppView_out_startingInfixToPostfix();

void AppView_showOperatorToken(char aToken);

void AppView_out_startingPostfix();

void AppView_out_resultForPostfix(char* postfixExpression);

void AppView_out_evaluatedValue(int anEvaluateValue);

Boolean AppView_in_InfixExpression(char* aExpression);

void  AppView_out_postfixEvaluationErrorMessage(PostfixError aPostfixError);



