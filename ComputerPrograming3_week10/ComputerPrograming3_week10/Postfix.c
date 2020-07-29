#define _CRT_SECURE_NO_WARNINGS
#include"Postfix.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct  _Postfix
{
	int _maxNumberOfTokens;
	char* _expression;
	int _evaluatedValue;
	Stack* _operandStack;
};

Postfix* Postfix_new(int givenMaxNumberOfTokens)
{
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens);
	_this->_operandStack = Stack_new(givenMaxNumberOfTokens);
	return _this;
}

void Postfix_delete(Postfix* _this)
{
	Stack_delete(_this->_operandStack);
	free(_this->_expression);
	free(_this);
}

void Postfix_setExpression(Postfix* _this, char* anExpression)
{
	strcpy(_this->_expression, anExpression);
}

int Postfix_evaluatedValue(Postfix* _this)
{
	return (_this->_evaluatedValue);
}

void Postfix_showTokenAndStack(Postfix* _this, int aCurrentToken)
{
	char buffer[50];
	//스택연산의 과정을 보여야 하기에 model에서 출력허용.
	sprintf_s(buffer, sizeof(buffer), "%c : Stack <Bottom> ", aCurrentToken);
	AppView_out(buffer);
	

	for (int i = 0; i < Stack_size(_this->_operandStack); i++) {
		AppView_showToken(Stack_elementAt(_this->_operandStack, i));
	}

	AppView_out(" <Top> \n");
}

Boolean Postfix_evaluate(Postfix* _this)
{
	int operand;  
	int operand1; 
	int operand2;
	int calculated;
	char currentToken;
	int i = 0;
	Stack_reset(_this->_operandStack);

	while (_this->_expression[i] != '\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9') {
			operand = (currentToken - '0');
			if (Stack_isFull(_this->_operandStack)) {
				return FALSE;//수식이 너무 길어 처리불가
			}
			else {
				Stack_push(_this->_operandStack, operand);
			}
		}
		else {
			if (currentToken == '+') {
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 + operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else
				{
					return FALSE;
				}
			}
			else if (currentToken == '-') {

				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 - operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					return FALSE;
				}
			}
			else if (currentToken == '*') {

				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 * (operand2);
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					return FALSE;
				}
			}
			else if (currentToken == '/') {
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					if (operand2 == 0) return  FALSE;
					calculated = operand1 / operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					return FALSE;
				}
			}
			else if (currentToken == '%') {
				if (Stack_size(_this->_operandStack) >= 2) {
					operand2 = Stack_pop(_this->_operandStack);
					operand1 = Stack_pop(_this->_operandStack);
					calculated = operand1 % operand2;
					Stack_push(_this->_operandStack, calculated);
				}
				else {
					return FALSE;
				}
			}
			else {
				return FALSE;
			}
		}
		Postfix_showTokenAndStack(_this, currentToken);
		i++;
	}

	if (Stack_size(_this->_operandStack) == 1) {
		_this->_evaluatedValue = Stack_pop(_this->_operandStack);
	}
	else if (Stack_size(_this->_operandStack) > 1) {
		return FALSE;
	}

	return TRUE;
}