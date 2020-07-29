#include"VStack.h"
#include<stdlib.h>

struct _VStack {
	int _size;
	VNode* _top;
};

VStack* VStack_new()
{
	VStack* _this;
	_this = NewObject(VStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}

Boolean VStack_isEmpty(VStack* _this) {
	return (_this->_size == 0);
}

Boolean VStack_isFull(VStack * _this) {
	return FALSE;
}

Boolean VStack_push(VStack * _this, ElementForVStack anElement)
{
	if (VStack_isFull(_this)) {
		return FALSE;
	}
	VNode* nodeForPush = VNode_new();
	VNode_setElement(nodeForPush, anElement);
	VNode_setNext(nodeForPush, _this->_top);
	_this->_top = nodeForPush;
	_this->_size++;
	return TRUE;
}

ElementForVStack VStack_pop(VStack * _this)
{
	if (VStack_isEmpty(_this)) {
		return FALSE;
	}
	else {
		VNode* poppedNode = _this->_top;
		ElementForVStack poppedElement = VNode_element(poppedNode);
		_this->_top = VNode_next(poppedNode);
		VNode_delete(poppedNode);
		_this->_size--;
		return poppedElement;
	}
}

void VStack_reset(VStack * _this)
{
	if (_this->_size != 0) {
		_this->_size = 0;
		VStack_deleteLinkedChain(_this);
	}
}

int VStack_size(VStack * _this) {
	return _this->_size;
}

ElementForVStack VStack_elementAt(VStack * _this, int anOrder)
{
	VNode* currentNode = _this->_top;
	ElementForVStack ElementNode;
	for (int i = 0; i < anOrder; i++) {
		currentNode = VNode_next(currentNode);
	}
	ElementNode = VNode_element(currentNode);
	return ElementNode;
}

void VStack_delete(VStack* _this) {
	VStack_deleteLinkedChain(_this);
	free(_this);
}

void VStack_deleteLinkedChain(VStack* _this) {
	VNode* currentNode = _this->_top;
	VNode* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {

		nodeToBeDeleted = currentNode;
		currentNode = VNode_next(currentNode);
		VNode_delete(nodeToBeDeleted);
	}
}

