#include"Stack.h"
#include<stdlib.h>

struct _Stack {
	int _capacity;
	int _top;
	Element* _elements;
};

Stack* Stack_new(int givenCapacity)
{
	Stack* _this;
	_this = NewObject(Stack);
	_this->_capacity = givenCapacity;
	_this->_top = -1;
	_this->_elements = NewVector(Element, givenCapacity);
	return _this;
}

Boolean Stack_isEmpty(Stack* _this) {
	return (_this->_top < 0);
}

Boolean Stack_isFull(Stack* _this) {
	return (_this->_top+1 == _this->_capacity);
}

Boolean Stack_push(Stack* _this, int anOperand)
{
	if (Stack_isFull(_this)) {
		return FALSE;
	}
	else
	{
		_this->_top++;
		_this->_elements[_this->_top] = anOperand;
		return TRUE;
	}
}

Element Stack_pop(Stack* _this)
{
	if (Stack_isEmpty(_this)) {
		return -9999;//에러임을 표시하기 위함.
	}
	else {
		Element poppedElement;
		poppedElement = _this->_elements[_this->_top];
		_this->_top--;
		return poppedElement;
	}
}

void Stack_reset(Stack* _this)
{
	_this->_top = -1;
}

int Stack_size(Stack* _this) {
	return (_this->_top + 1);
}

Element Stack_elementAt(Stack* _this, int anOrder)
{
	return (_this->_elements[anOrder]);//Bottom이 0번째 순서.
}

void Stack_delete(Stack* _this) {
	free(_this->_elements);
	free(_this);
}
