#include"UnsortedLinkedDictionary.h"
#include<stdlib.h>

struct _UnsortedLinkedDictionary {
	int _size;
	Node* _head; 
};

UnsortedLinkedDictionary* UnsortedLinkedDictionary_new()
{
	UnsortedLinkedDictionary* _this = NewObject(UnsortedLinkedDictionary);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void  UnsortedLinkedDictionary_delete(UnsortedLinkedDictionary* _this)
{
	Node* currentNode = _this->_head;
	Node* deleteNode = NULL;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(deleteNode);
	}
}

Boolean UnsortedLinkedDictionary_isEmpty(UnsortedLinkedDictionary* _this)
{
	return (_this->_size == 0);
}

Boolean  UnsortedLinkedDictionary_isFull(UnsortedLinkedDictionary * _this)
{
	return FALSE;
}

void  UnsortedLinkedDictionary_addKeyAndObject(UnsortedLinkedDictionary * _this, Key * aKey, Object * anObject)
{
	Node* nodeForAdd = Node_new();
	Node_setKey(nodeForAdd, aKey);
	Node_setObject(nodeForAdd, anObject);
	Node_setNext(nodeForAdd, _this->_head);
	_this->_head = nodeForAdd;
	_this->_size++;
}

Boolean UnsortedLinkedDictionary_keyDoesExist(UnsortedLinkedDictionary * _this, Key * aKey)
{
	Node* currentNode = _this->_head;
	while (currentNode != NULL) {
		if (Key_compareTo(aKey, Node_key(currentNode))==0) {
			return TRUE;
		}
		currentNode = Node_next(currentNode);
	}
	return FALSE;
}

// Element=Object but Element*!=Object* 
Element* UnsortedLinkedDictionary_removeObjectForKey(UnsortedLinkedDictionary * _this, Key * aKey)
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

