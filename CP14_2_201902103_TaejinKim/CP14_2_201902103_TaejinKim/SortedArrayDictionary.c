#include"SortedArrayDictionary.h"
#include<stdlib.h>

struct _SortedArrayDictionary {
	int _capacity;
	int _size;
	BinaryNode** _elements;
};


SortedArrayDictionary* SortedArrayDictionary_new(int maxSize)
{
	SortedArrayDictionary* _this = NewObject(SortedArrayDictionary);
	_this->_capacity = maxSize;
	_this->_elements = NewVector(BinaryNode*, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void  SortedArrayDictionary_delete(SortedArrayDictionary* _this)
{

	free(_this->_elements);
	free(_this);
}

Boolean  SortedArrayDictionary_isEmpty(SortedArrayDictionary* _this)
{
	return (_this->_size == 0);
}

Boolean  SortedArrayDictionary_isFull(SortedArrayDictionary* _this)
{
	return (_this->_size == _this->_capacity);
}

void  SortedArrayDictionary_addKeyAndObject(SortedArrayDictionary* _this, Key* aKey, Object* anObject)
{
	int positionForAdd = SortedArrayList_positionUsingBinarySearch(_this, aKey);
	SortedArrayList_addAt(_this, aKey,anObject,positionForAdd);
}


int SortedArrayList_positionUsingBinarySearch(SortedArrayDictionary* _this, Key* aKey)
{

	int left = 0;
	int right = _this->_size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (Key_compareTo(aKey, BinaryNode_key(_this->_elements[mid]))) {
			return mid;
		}
		else if (Key_compareTo(aKey, BinaryNode_key(_this->_elements[mid]))<0) {
			right = mid - 1;
		}
		else if (Key_compareTo(aKey, BinaryNode_key(_this->_elements[mid])) > 0) {
			left = mid + 1;
		}
	}
	return left;
}

void SortedArrayList_addAt(SortedArrayDictionary* _this, Key* aKey,Object* anObject, int aPosition)
{
	for (int i = aPosition; i < _this->_size - 1; i++)
	{
		_this->_elements[i + 1] = _this->_elements[i];
	}
	_this->_elements[aPosition] = BinaryNode_newWith(aKey, anObject, NULL, NULL);
	(_this->_size)++;
}

Boolean  SortedArrayDictionary_keyDoesExist(SortedArrayDictionary* _this, Key* aKey)
{
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(aKey, BinaryNode_key(_this->_elements[i])) == 0) {
			return TRUE;
		}
	}
	return FALSE;
}

Element* SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary* _this, Key* aKey)
{
	int aPosition = SortedArrayList_positionUsingBinarySearch(_this,aKey);
	
	                   
	Element* removedElement = BinaryNode_object(_this->_elements[aPosition]);
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[i - 1] = _this->_elements[i];
	}
	_this->_size--;
	return removedElement;
}

