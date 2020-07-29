#define MAX_NUMBER_OF_TOKENS 200
#include"AppController.h"
#include<stdlib.h>


struct _AppController
{
	char _expression[MAX_NUMBER_OF_TOKENS];
	Postfix* _postfix;
	Infix* _infix;
};

AppController* AppController_New()
{
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this)
{
	Boolean InfixExpressionIsAvailable;
	PostfixError evaluationError;
	Boolean InfixToPostfixError;

	AppView_out_startingMessage();

	_this->_infix = Infix_new();
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
	
	InfixExpressionIsAvailable = AppView_in_InfixExpression(_this->_expression);
	while (InfixExpressionIsAvailable) {
		
		AppView_out_startingInfixToPostfix();
		/* infix°´Ã¼ »ý¼º */
		Infix_setExpression(_this->_infix, _this->_expression);
		InfixToPostfixError = Infix_toPostfix(_this->_infix);
		if (InfixToPostfixError != FALSE) {
			AppView_out_resultForPostfix(Infix_postfix(_this->_infix));
		}
		else {
			AppView_out_errorInExpression();
		}
		AppView_out("\n\n");
		AppView_out_startingPostfix();
		Postfix_setExpression(_this->_postfix, Infix_postfix(_this->_infix));
		evaluationError = Postfix_evaluate(_this->_postfix);
		
		if (evaluationError == PostfixError_None) {
			AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		
		else {
			AppView_out_postfixEvaluationErrorMessage(evaluationError);
		}
	
		InfixExpressionIsAvailable = AppView_in_InfixExpression(_this->_expression);
	}
	Postfix_delete(_this->_postfix);
	Infix_delete(_this->_infix);
	AppView_out_endingMessage();
}

void AppController_delete(AppController* _this)
{
	free(_this);
}
