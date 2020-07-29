#include"UnsortedLinkedList.h"

struct _UnsortedLinkedList {
	int _size;
	Node* _head;
};

UnsortedLinkedList* UnsortedLinkedList_new()
{
	UnsortedLinkedList* _this = NewObject(UnsortedLinkedList);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void UnsortedLinkedList_delete(UnsortedLinkedList* _this)
{
	Node* currentNode = _this->_head;
	Node* deleteNode = NULL;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(deleteNode);
	}
}

Boolean UnsortedLinkedList_isEmpty(UnsortedLinkedList* _this)
{
	return (_this->_size == 0);
}

Boolean UnsortedLinkedList_isFull(UnsortedLinkedList * _this)
{
	return FALSE;
}

Boolean UnsortedLinkedList_add(UnsortedLinkedList * _this, Element anElement)
{
	if (UnsortedLinkedList_isFull(_this)) {
		return FALSE;
	}
	else {
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		Node_setNext(nodeForAdd, _this->_head);
		_this->_head = nodeForAdd;
		_this->_size++;
		return TRUE;
	}
}

Element UnsortedLinkedList_min(UnsortedLinkedList * _this)
{
	if (UnsortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else
	{
		int min = Node_element(_this->_head);
		Node* currentNode = Node_next(_this->_head);
		while (currentNode != NULL) {
			if (Node_element(currentNode) < min) {
				min = Node_element(currentNode);
			}
			currentNode = Node_next(currentNode);
		}
		return min;
	}
}

Element UnsortedLinkedList_removeMax(UnsortedLinkedList * _this)
{
	if (UnsortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {
		int max = Node_element(_this->_head);
		Node* currentNode = _this->_head;
		Node* nextNode = Node_next(_this->_head);
		Node* previousNodeOfMax = NULL;

		while (nextNode != NULL) {
			if (Node_element(nextNode) > max) {
				max = Node_element(nextNode);
				previousNodeOfMax = currentNode;
			}
			currentNode = nextNode;
			nextNode = Node_next(nextNode);
		}
		Node* removedNode = NULL;
		if (previousNodeOfMax == NULL) {
			removedNode = _this->_head;
			_this->_head = Node_next(_this->_head);
		}
		else {
			removedNode = Node_next(previousNodeOfMax);
			Node_setNext(previousNodeOfMax, Node_next(removedNode));
		}
		_this->_size--;
		Node_delete(removedNode);
		return max;
	}
}
