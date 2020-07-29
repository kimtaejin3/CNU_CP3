#include"Stack.h"
#include<stdlib.h>
#define DEFAULT_STACK_CAPACITY 100

struct _Stack {
	int _capacity;
	int _top;
	Element* _elements;
};


Stack* Stack_new() {
	Stack* _this = NewObject(Stack);
	_this->_capacity = DEFAULT_STACK_CAPACITY;
	_this->_elements = NewVector(Element, _this->_capacity);
	_this->_top = -1;
	return _this;
}
	
void Stack_delete(Stack* _this) {
	free(_this->_elements);
	free(_this);
}

Boolean Stack_isEmpty(Stack* _this)
{
	return (_this->_top <0);
}

Boolean Stack_isFull(Stack* _this)
{
	return ((_this->_top) == (_this->_capacity - 1));
}

int Stack_size(Stack* _this)
{
	return (_this->_top + 1);
}

Boolean Stack_push(Stack* _this, Element anElement)
{
	if (Stack_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_top++;
		_this->_elements[_this->_top] = anElement;
		return TRUE;
	}
}

Element* Stack_pop(Stack* _this)
{
	Element *poppedElement;

	if (Stack_isEmpty(_this)) {
		return NULL;
	}
	else{
		poppedElement = malloc(sizeof(Element));
		*poppedElement = _this->_elements[_this->_top];
		_this->_top--;
		return poppedElement;
	}
}

Element Stack_topElement(Stack* _this)
{
	return (_this->_elements[_this->_top]);
}

Element Stack_elementAt(Stack* _this, int anOrder)
{
	return (_this->_elements[anOrder]);//Bottom이 0번째 순서.
}

