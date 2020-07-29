#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUMBER_OF_TOKENS 200
#include"Infix.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct _Infix {
	char* _infixExpression;
	char* _postfixExpression;
	OStack* _operatorStack;
};

Infix* Infix_new()
{
	Infix* _this = NewObject(Infix);
	if (_this != NULL) {
		_this->_operatorStack = OStack_new();
		_this->_infixExpression = NewVector(char, MAX_NUMBER_OF_TOKENS);
		_this->_postfixExpression = NewVector(char, MAX_NUMBER_OF_TOKENS);
	}return _this;
}

void  Infix_delete(Infix* _this)
{
	OStack_delete(_this->_operatorStack);
	free(_this->_infixExpression);
	free(_this->_postfixExpression);
	free(_this);
}

void Infix_setExpression(Infix* _this, char* newExpression)
{
	strcpy(_this->_infixExpression ,newExpression);
}

void Infix_showTokenAndStack(Infix* _this, char aCurrentToken)
{
	char buffer[50];
	//스택연산의 과정을 보여야 하기에 model에서 출력허용.
	sprintf_s(buffer, sizeof(buffer), "%c : OStack <Bottom> ", aCurrentToken);
	AppView_out(buffer);


	for (int i = OStack_size(_this->_operatorStack)-1; i >= 0; i--) {
		AppView_showOperatorToken(OStack_elementAt(_this->_operatorStack,i));
	}

	AppView_out(" <Top> \n");
}

Boolean  Infix_toPostfix(Infix* _this) {
	int i = 0;
	int p = 0;

	char currentToken = 0, poppedToken = 0;
	int infixSize = strlen(_this->_infixExpression);
	_this->_operatorStack = OStack_new(infixSize);
	while (i < infixSize) {
		currentToken = _this->_infixExpression[i++];
		if (isDigit(currentToken)) {
			_this->_postfixExpression[p++] = currentToken;
		}
		else {
			if (currentToken == ')') {
				if (OStack_isEmpty(_this->_operatorStack)) {
					return FALSE;
				}
				else {
					poppedToken = OStack_pop(_this->_operatorStack);
					while (poppedToken != '(') {
						_this->_postfixExpression[p++] = poppedToken;
						if (OStack_isEmpty(_this->_operatorStack)) {
							return FALSE;
						}
						else {
							poppedToken = OStack_pop(_this->_operatorStack);
						}
					}
				}
			}
			else {
				int inComingPrecedence = Infix_inComingPrecedence(currentToken);
				while (!OStack_isEmpty(_this->_operatorStack) && Infix_inStackPrecedence(OStack_topElement(_this->_operatorStack)) >= inComingPrecedence) {
					poppedToken = OStack_pop(_this->_operatorStack);
					_this->_postfixExpression[p++] = poppedToken;
				}
				OStack_push(_this->_operatorStack, currentToken);
			}
		}
		Infix_showTokenAndStack(_this, currentToken);
	}
	while (!OStack_isEmpty(_this->_operatorStack)) {
		poppedToken = OStack_pop(_this->_operatorStack);
		_this->_postfixExpression[p++] = poppedToken;
	}
	_this->_postfixExpression[p] = '\0';
	return TRUE;
}

int  Infix_inComingPrecedence(char aToken) { // 각 연산자의 입력 토큰 상태의 우선 순위를 돌려준다

	if (aToken == '(') {
		return 20;
	}
	else if (aToken == ')') {
		return 19;
	}
	else if (aToken == '^') {
		return 17;
	}
	else if (aToken == '*') {
		return 13;
	}
	else if (aToken == '/') {
		return 13;
	}
	else if (aToken == '%') {
		return 13;
	}
	else if (aToken == '+') {
		return 12;
	}
	else if (aToken == '-') {
		return 12;
	}
	else if (aToken == '$') {
		return 0;
	}
	else {
		return -1;
	}
}


int  Infix_inStackPrecedence(char aToken) {

	if (aToken == '^') {
		return 16;
	}
	else if (aToken == '*') {
		return 13;
	}
	else if (aToken == '/') {
		return 13;
	}
	else if (aToken == '%') {
		return 13;
	}
	else if (aToken == '+') {
		return 12;
	}
	else if (aToken == '-') {
		return 12;
	}
	else if (aToken == '$') {
		return 0;
	}
	else {
		return -1;
	}
}
char* Infix_postfix(Infix* _this) {
	return _this->_postfixExpression;
}
