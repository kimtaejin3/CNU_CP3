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
	VStack* _operandStack;
};

Postfix* Postfix_new(int givenMaxNumberOfTokens)
{
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens);
	_this->_operandStack = VStack_new();
	return _this;
}

void Postfix_delete(Postfix* _this)
{
	VStack_delete(_this->_operandStack);
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
	sprintf_s(buffer, sizeof(buffer), "%c : VStack <Bottom> ", aCurrentToken);
	AppView_out(buffer);


	for (int i = VStack_size(_this->_operandStack)-1; i >= 0;  i--) {
		AppView_showToken(VStack_elementAt(_this->_operandStack, i));
	}

	AppView_out(" <Top> \n");
}

PostfixError Postfix_evaluate(Postfix* _this)
{
	int operand;
	int operand1;
	int operand2;
	int calculated;
	char currentToken;
	int i = 0;
	VStack_reset(_this->_operandStack);

	while (_this->_expression[i] != '\0') {
		currentToken = _this->_expression[i];
		if (currentToken >= '0' && currentToken <= '9') {
			operand = (currentToken - '0');
			if (VStack_isFull(_this->_operandStack)) {
				return PostfixError_ExpressionTooLong;//수식이 너무 길어 처리불가->연결리스트에서는 제한없음.
			}
			else {
				VStack_push(_this->_operandStack, operand);
			}
		}
		else {
			if (currentToken == '+') {
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 + operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else
				{
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '-') {

				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 - operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '*') {

				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 * (operand2);
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '/') {
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					if (operand2 == 0) return  PostfixError_DivideByZero;
					calculated = operand1 / operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					return PostfixError_OperandsTooFew;
				}
			}
			else if (currentToken == '%') {
				if (VStack_size(_this->_operandStack) >= 2) {
					operand2 = VStack_pop(_this->_operandStack);
					operand1 = VStack_pop(_this->_operandStack);
					calculated = operand1 % operand2;
					VStack_push(_this->_operandStack, calculated);
				}
				else {
					return PostfixError_OperandsTooFew;
				}
			}
			else {
				return PostfixError_UnknownOperator;
			}
		}
		Postfix_showTokenAndStack(_this, currentToken);
		i++;
	}

	if (VStack_size(_this->_operandStack) == 1) {
		_this->_evaluatedValue = VStack_pop(_this->_operandStack);
	}
	else if (VStack_size(_this->_operandStack) > 1) {
		return PostfixError_OperandsTooMany;
	}

	return PostfixError_None;
}