#define VALUE_FOR_EMPTY - 1;
#include"Queue.h"
#include<stdlib.h>

struct _Queue {
	Node* _front;
	Node* _rear;
	int _size;
};

Queue* Queue_new()
{
	Queue* _this;
	_this = NewObject(Queue);
	_this->_size = 0;
	_this->_front = NULL;
	_this->_rear = NULL;
	return _this;
}

void Queue_delete(Queue* _this) {
	Queue_deleteLinkedChain(_this);
	free(_this);
}

void Queue_deleteLinkedChain(Queue* _this)
{
	Node* currentNode = _this->_front;
	Node* deleteNode;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		Node_delete(deleteNode);
		Node_setNext(currentNode, Node_next(currentNode));
	}
}

Boolean Queue_isEmpty(Queue* _this)
{
	return (_this->_size == 0);
}

Boolean Queue_isFull(Queue* _this)
{
	return FALSE;
}

int Queue_size(Queue* _this)
{
	return (_this->_size);
}

Boolean Queue_add(Queue* _this, Element anElement)
{
	if (Queue_isFull(_this)) {
		return FALSE;
	}
	else
	{
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		if (Queue_isEmpty(_this)) {
			_this->_front = nodeForAdd;
		}
		else {
			Node_setNext(_this->_rear, nodeForAdd);
		}
		_this->_rear = nodeForAdd;
		_this->_size++;
		return TRUE;
	}
}

Element Queue_remove(Queue* _this)
{
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else
	{
		Node* removedNode = _this->_front;
		if (_this->_size == 1) {
			_this->_front = NULL;
			_this->_rear = NULL;
		}
		else {
			_this->_front = Node_next(_this->_front);
		}
		Element removedElement = Node_element(removedNode);
		Node_delete(removedNode);
		_this->_size--;
		return removedElement;
	}
}

Element Queue_Front(Queue* _this)
{
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else
	{
		Element frontElement = Node_element(_this->_front);
		return frontElement;
	}
}

Element Queue_elementAt(Queue* _this, int anOrder)
{
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else
	{
		int nodeCount = 0;
		Node* currentNode = _this->_front;
		while (nodeCount < anOrder) {
			currentNode = Node_next(currentNode);
			nodeCount++;
		}
		return Node_element(currentNode);
	}
}
