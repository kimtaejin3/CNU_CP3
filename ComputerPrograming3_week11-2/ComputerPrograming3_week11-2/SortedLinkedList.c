#include"SortedLinkedList.h"

struct _SortedLinkedList {
	int _size;
	Node* _head;
};

SortedLinkedList* SortedLinkedList_new() {
	SortedLinkedList* _this = NewObject(SortedLinkedList);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void SortedLinkedList_delete(SortedLinkedList* _this)
{
	Node* currentNode = _this->_head;
	Node* deleteNode = NULL;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(deleteNode);
	}
}

Boolean SortedLinkedList_isEmpty(SortedLinkedList* _this) {
	return (_this->_size == 0);
}

Boolean SortedLinkedList_isFull(SortedLinkedList* _this)
{
	return FALSE;
}

Boolean SortedLinkedList_add(SortedLinkedList* _this, Element anElement)
{
	if (SortedLinkedList_isFull(_this)) {
		return FALSE;
	}
	else
	{
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		Node_setNext(nodeForAdd, NULL);
		if (SortedLinkedList_isEmpty(_this)) {
			_this->_head = nodeForAdd;
		}
		else {
			Node* previousNode = NULL;
			Node* currentNode = _this->_head;
			while (currentNode != NULL && Node_element(currentNode) < anElement) {
				previousNode = currentNode;
				currentNode = Node_next(currentNode);
			}
			if (previousNode == NULL) {
				Node_setNext(nodeForAdd, _this->_head);
				_this->_head = nodeForAdd;
			}
			else {
				Node_setNext(nodeForAdd, currentNode);
				Node_setNext(previousNode, nodeForAdd);
			}
		}
		_this->_size;
		return TRUE;
	}
}

Element SortedLinkedList_min(SortedLinkedList* _this)
{
	if (SortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {
		int min = Node_element(_this->_head);
		return min;
	}
}

Element SortedLinkedList_removeMax(SortedLinkedList* _this) {
	
	if (SortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {
		Node* maxNode = NULL;
		if (_this->_size == 1) {
			maxNode = _this->_head;
			int max = Node_element(maxNode);
			
			_this->_head = NULL;
			_this->_size--;
			return max;
		}
		else
		{
			Node* previousNode = _this->_head;
			Node* currentNode = Node_next(_this->_head);
			Node* nextNode = Node_next(currentNode);
			while (nextNode != NULL) {
				previousNode = currentNode;
				currentNode = nextNode;
				nextNode = Node_next(nextNode);
			}
			maxNode = currentNode;
			Node_setNext(previousNode, NULL);
			
			int max = Node_element(maxNode);
			_this->_size--;
			Node_delete(currentNode);
			return max;
		}
	}
}
