#include"UnsortedArrayDictionary.h"
#include<stdlib.h>

struct _UnsortedArrayDictionary {
	int _capacity;
	int _size;
	BinaryNode** _elements;
};


UnsortedArrayDictionary* UnsortedArrayDictionary_new(int maxSize)
{
	UnsortedArrayDictionary* _this = NewObject(UnsortedArrayDictionary);
	_this->_capacity = maxSize;
	_this->_elements = NewVector(BinaryNode*, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void UnsortedArrayDictionary_delete(UnsortedArrayDictionary* _this)
{
	free(_this->_elements);
	free(_this);
}

Boolean UnsortedArrayDictionary_isEmpty(UnsortedArrayDictionary* _this) {
	return (_this->_size == 0);
}

Boolean UnsortedArrayDictionary_isFull(UnsortedArrayDictionary* _this)
{
	return (_this->_size == _this->_capacity);
}

void UnsortedArrayDictionary_addKeyAndObject(UnsortedArrayDictionary* _this, Key* aKey, Object* anObject)
{
	_this->_elements[_this->_size] = BinaryNode_newWith(aKey, anObject, NULL, NULL);
	(_this->_size)++;	
}

Boolean  UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary* _this, Key* aKey)
{
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(aKey, BinaryNode_key(_this->_elements[i])) == 0) {
			return TRUE;
		}
	}
	return FALSE;
}

Element* UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary* _this, Key* aKey)
{
	int aPosition = -1;
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(aKey, BinaryNode_key(_this->_elements[i])) == 0) {
			aPosition = i;
		}
	}
	Element* removedElement = BinaryNode_object(_this->_elements[aPosition]);
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[i - 1] = _this->_elements[i];
	}
	_this->_size--;
	return removedElement;
}


