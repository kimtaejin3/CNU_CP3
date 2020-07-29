#include"OStack.h"
#include<stdlib.h>

struct _OStack {
	int _size;
	ONode* _top;
};

OStack* OStack_new()
{
	OStack* _this;
	_this = NewObject(OStack);
	_this->_size = 0;
	_this->_top = NULL;
	return _this;
}

Boolean OStack_isEmpty(OStack* _this) {
	return (_this->_size == 0);
}

Boolean OStack_isFull(OStack * _this) {
	return FALSE;
}

Boolean OStack_push(OStack * _this, ElementForOStack anElement)
{
	if (OStack_isFull(_this)) {
		return FALSE;
	}
	ONode* nodeForPush = ONode_new();
	ONode_setElement(nodeForPush, anElement);
	ONode_setNext(nodeForPush, _this->_top);
	_this->_top = nodeForPush;
	_this->_size++;
	return TRUE;
}

ElementForOStack OStack_pop(OStack * _this)
{
	if (OStack_isEmpty(_this)) {
		return FALSE;
	}
	else {
		ONode* poppedNode = _this->_top;
		ElementForOStack poppedElement = ONode_element(poppedNode);
		_this->_top = ONode_next(poppedNode);
		ONode_delete(poppedNode);
		_this->_size--;
		return poppedElement;
	}
}

void OStack_reset(OStack * _this)
{
	if (_this->_size != 0) {
		_this->_size = 0;
		OStack_deleteLinkedChain(_this);
	}
}

int OStack_size(OStack * _this) {
	return _this->_size;
}

ElementForOStack OStack_elementAt(OStack * _this, int anOrder)
{
	ONode* currentNode = _this->_top;
	ElementForOStack ElementNode;
	for (int i = 0; i < anOrder; i++) {
		currentNode = ONode_next(currentNode);
	}
	ElementNode = ONode_element(currentNode);
	return ElementNode;
}

ElementForOStack OStack_topElement(OStack* _this) {
	ElementForOStack topElement = ONode_element(_this->_top);
	return topElement;
}

void OStack_delete(OStack * _this) {
	OStack_deleteLinkedChain(_this);
	free(_this);
}

void OStack_deleteLinkedChain(OStack * _this) {
	ONode* currentNode = _this->_top;
	ONode* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {

		nodeToBeDeleted = currentNode;
		currentNode = ONode_next(currentNode);
		ONode_delete(nodeToBeDeleted);
	}
}

