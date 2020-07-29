#include"SortedLinkedDictionary.h"
#include<stdlib.h>

struct _SortedLinkedDictionary {
	int _size;
	BinaryNode* _head; // left는 NULL로 
						// 중요: *next 기능은 *right로 대체
						// 클래스를 따로 정의하지 않고 하기 위함.
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
	BinaryNode* currentNode = _this->_head;
	BinaryNode* deleteNode = NULL;
	while (currentNode != NULL) {
		deleteNode = currentNode;
		currentNode = BinaryNode_right(currentNode);
		BinaryNode_delete(deleteNode);
	}
}

Boolean SortedLinkedDictionary_isEmpty(SortedLinkedDictionary* _this)
{
	return (_this->_size == 0);
}

Boolean  SortedLinkedDictionary_isFull(SortedLinkedDictionary* _this)
{
	return FALSE;
}

void  SortedLinkedDictionary_addKeyAndObject(SortedLinkedDictionary* _this, Key* aKey, Object* anObject)
{
	BinaryNode* nodeForAdd = BinaryNode_newWith(aKey,anObject,NULL,NULL); // BinaryNode를 그대로 사용했기때문에 right를 next로 임의 설정함
	if (SortedLinkedDictionary_isEmpty(_this)) {
		_this->_head = nodeForAdd;
	}
	else {
		BinaryNode* previousNode = NULL;
		BinaryNode* currentNode = _this->_head;
		while (currentNode != NULL && Key_compareTo(aKey, BinaryNode_key(currentNode))>0) {
			previousNode = currentNode;
			currentNode = BinaryNode_right(currentNode);
		}
		if (previousNode == NULL) {
			BinaryNode_setRight(nodeForAdd, _this->_head);
			_this->_head = nodeForAdd;
		}
		else {
			BinaryNode_setRight(nodeForAdd, currentNode);
			BinaryNode_setRight(previousNode, nodeForAdd);
		}
	}
	_this->_size++;
}

Boolean SortedLinkedDictionary_keyDoesExist(SortedLinkedDictionary* _this, Key* aKey)
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

Element* SortedLinkedDictionary_removeObjectForKey(SortedLinkedDictionary* _this, Key* aKey)
{
	Element* removedElement = NULL;
	BinaryNode* currentNode = _this->_head;
	BinaryNode* previousNode = NULL;

	while (currentNode != NULL) {
		if (Key_compareTo(aKey, BinaryNode_key(currentNode)) == 0) {
			removedElement = BinaryNode_object(currentNode);
			previousNode = currentNode;
		}
		previousNode = currentNode;
		currentNode = BinaryNode_right(currentNode);
	}


	return removedElement;
}


