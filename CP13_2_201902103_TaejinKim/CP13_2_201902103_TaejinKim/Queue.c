/*Circular Array Queue*/
#define VALUE_FOR_EMPTY - 1;
#define ORDER_NOT_VALID - 1;
#include"Queue.h"
#include<stdlib.h>

struct _Queue {
	Element* _elements;
	int _front;
	int _rear;
	int _maxLength;
};

Queue* Queue_new(int givenCapacity)
{
	Queue* _this = NewObject(Queue);
	 _this->_maxLength = givenCapacity+1;
	 _this->_elements = NewVector(Element, _this->_maxLength);
	 _this->_front = 0;
	 _this->_rear= 0;
	 return _this;
}

void Queue_delete(Queue* _this) {
	free(_this->_elements);
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this)
{
	return(_this->_front == _this->_rear);
}

Boolean Queue_isFull(Queue * _this)
{
	int nextRear = (_this->_rear + 1) % _this->_maxLength;
	return(nextRear == _this->_front);
}

int Queue_size(Queue * _this)
{
	if (_this->_front <= _this->_rear) {
		return (_this->_rear - _this->_front);
	}
	else
	{
		return (((_this->_rear)+(_this->_maxLength))-(_this->_front));
	}
}

Boolean Queue_add(Queue * _this, Element anElement)
{
	if (Queue_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_rear = (_this->_rear + 1) % (_this->_maxLength);
		_this->_elements[_this->_rear] = anElement;

		return TRUE;
	}
}

Element Queue_remove(Queue * _this)
{
	Element removedElement;
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else {
		_this->_front = (_this->_front + 1) % (_this->_maxLength);
		removedElement = _this->_elements[_this->_front];
		return removedElement;
	}
}

Element Queue_Front(Queue * _this)
{
	Element frontElement;
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else {
		frontElement = _this->_elements[_this->_front+1];
		return frontElement;
	}
}

Element Queue_elementAt(Queue * _this, int anOrder)
{
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	if (0<=anOrder&&anOrder < Queue_size(_this)) {
		return _this->_elements[(anOrder + _this->_front + 1)%(_this->_maxLength)];
	}
	else {
		return ORDER_NOT_VALID;//ÀÎµ¦½º°¡ Àß¸ø µÊ.
	}
}
