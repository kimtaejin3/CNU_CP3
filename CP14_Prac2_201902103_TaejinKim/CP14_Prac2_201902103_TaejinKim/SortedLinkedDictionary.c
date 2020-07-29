#include"SortedLinkedDictionary.h"
#include<stdlib.h>

struct _SortedLinkedDictionary {
	int _size;
	Node* _head; 
};

SortedLinkedDictionary* SortedLinkedDictionary_new()
{
	SortedLinkedDictionary* _this = NewObject(SortedLinkedDictionary);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void  SortedLinkedDictionary_delete(SortedLinkedDictionary* _this)
{
	Node* currentNode = _this->_head;
	Node* deleteNode = NULL;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(deleteNode);
	}
}

Boolean SortedLinkedDictionary_isEmpty(SortedLinkedDictionary* _this)
{
	return (_this->_size == 0);
}

Boolean  SortedLinkedDictionary_isFull(SortedLinkedDictionary * _this)
{
	return FALSE;
}

void  SortedLinkedDictionary_addKeyAndObject(SortedLinkedDictionary * _this, Key * aKey, Object * anObject)
{
	
	Node* nodeForAdd = Node_new();
	Node_setKey(nodeForAdd, aKey); //키값 초기화
	Node_setObject(nodeForAdd, anObject); // 오브젝트 초기화
	Node_setNext(nodeForAdd, NULL);
	if (SortedLinkedDictionary_isEmpty(_this)) {
		_this->_head = nodeForAdd;
	}
	else {
		Node* previousNode = NULL;
		Node* currentNode = _this->_head;
		while (currentNode != NULL && Key_compareTo(aKey, Node_key(currentNode)) > 0) {
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
	_this->_size++;
}

Boolean SortedLinkedDictionary_keyDoesExist(SortedLinkedDictionary * _this, Key * aKey)
{

	Node* currentNode = _this->_head;
	while (currentNode != NULL) {
		if (Key_compareTo(aKey,Node_key(currentNode))==0) {
			return TRUE;
		}
		currentNode = Node_next(currentNode);
	}
	return FALSE;
}


Element* SortedLinkedDictionary_removeObjectForKey(SortedLinkedDictionary * _this, Key * aKey)
{
	Element* removedElement = NULL;
	Node* currentNode = _this->_head;
	Node* previousNode = NULL;

	while (currentNode != NULL) {
		if (Key_compareTo(aKey, Node_key(currentNode))==0) {
			removedElement = (Element*)Node_object(currentNode);
			previousNode = currentNode;
		}
		previousNode = currentNode;
		currentNode = Node_next(currentNode);
	}


	return removedElement;
}


