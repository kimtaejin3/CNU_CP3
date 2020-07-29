#define MAX_NUMBER_OF_TOKENS 200
#include"AppController.h"
#include<stdlib.h>

struct _AppController
{
	char _expression[MAX_NUMBER_OF_TOKENS];
	Postfix* _postfix;
};

AppController* AppController_New()
{
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this)
{
	Boolean expressionIsAvailable,noErrorIsInEvaluation;

	AppView_out_startingMessage();
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);//Stack�� ������ ���� Postfix���� ���ϵ��� ��.
	expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
	
	while (expressionIsAvailable) {
		Postfix_setExpression(_this->_postfix, _this->_expression);
		noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);
		if (!noErrorIsInEvaluation) {
			AppView_out_errorInExpression();
		}
		else {
			AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
	}

	Postfix_delete(_this->_postfix);
	AppView_out_endingMessage();
}

void AppController_delete(AppController* _this)
{
	free(_this);
}