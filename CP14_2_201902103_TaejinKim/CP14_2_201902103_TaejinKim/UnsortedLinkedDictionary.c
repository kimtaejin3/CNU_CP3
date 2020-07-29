#include"UnsortedLinkedDictionary.h"
#include<stdlib.h>

struct _UnsortedLinkedDictionary {
	int _size;
	BinaryNode* _head; // left는 NULL로 
						// 중요: *next 기능은 *right로 대체
						// 클래스를 따로 정의하지 않고 하기 위함.
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
	BinaryNode* currentNode = _this->_head;
	BinaryNode* deleteNode = NULL;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		currentNode = BinaryNode_right(currentNode);
		BinaryNode_delete(deleteNode);
	}
}

Boolean UnsortedLinkedDictionary_isEmpty(UnsortedLinkedDictionary* _this)
{
	return (_this->_size == 0);
}

Boolean  UnsortedLinkedDictionary_isFull(UnsortedLinkedDictionary* _this)
{
	return FALSE;
}

void  UnsortedLinkedDictionary_addKeyAndObject(UnsortedLinkedDictionary* _this, Key* aKey, Object* anObject)
{
	BinaryNode* nodeForAdd = BinaryNode_newWith(aKey,anObject,NULL,NULL);
	BinaryNode_setRight(nodeForAdd, _this->_head);
	_this->_head = nodeForAdd;
	_this->_size++;
}

Boolean UnsortedLinkedDictionary_keyDoesExist(UnsortedLinkedDictionary* _this, Key* aKey)
{
	BinaryNode* currentNode = _this->_head;
	while (currentNode != NULL) {
		if (Key_compareTo(aKey, BinaryNode_key(currentNode)) == 0) {
			return TRUE;
		}
		currentNode = BinaryNode_right(currentNode);
	}
	return FALSE;
}

// Element=Object
Element* UnsortedLinkedDictionary_removeObjectForKey(UnsortedLinkedDictionary* _this, Key* aKey)
{
	Element* removedElement=NULL;
	BinaryNode* currentNode = _this->_head;
	BinaryNode* previousNode = NULL;

	while (currentNode != NULL) {
		if (Key_compareTo(aKey, BinaryNode_key(currentNode)) == 0) {
			removedElement = BinaryNode_object(currentNode);
			previousNode = currentNode;
		}
		previousNode=currentNode;
		currentNode = BinaryNode_right(currentNode);
	}


	return removedElement;
}

