#include"SortedArrayDictionary.h"
#include<stdlib.h>

/*
	�߿�!
	0 < i < n
	Key -> _elements[0][i]
	Object -> _elements[1][i]
*/

struct _SortedArrayDictionary {
	int _capacity;
	int _size;
	Element** _elements;
};

SortedArrayDictionary* SortedArrayDictionary_new(int maxSize)
{
	SortedArrayDictionary* _this = NewObject(SortedArrayDictionary);
	_this->_capacity = maxSize;
	_this->_elements = NewToDimensionVector(int, 2);
	for (int i = 0; i < 2; i++)
	{
		_this->_elements[i] = NewVector(int, maxSize);
	}
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

Boolean  SortedArrayDictionary_isFull(SortedArrayDictionary * _this)
{
	return (_this->_size == _this->_capacity);
}

void  SortedArrayDictionary_addKeyAndObject(SortedArrayDictionary * _this, Key * aKey, Object * anObject)
{
	// ��1�ܰ�: ������ ��ġ�� �����Ѵ�
	int positionForAdd = SortedArrayList_positionUsingBinarySearch(_this, aKey);
	// ��2�ܰ�: ã���� ���� ��ġ�� �־��� ���Ҹ� �����Ѵ�
	SortedArrayList_addAt(_this, aKey, anObject, positionForAdd);
}


int SortedArrayList_positionUsingBinarySearch(SortedArrayDictionary* _this, Key* aKey)
{

	int left = 0;
	int right = _this->_size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (Key_value(aKey) == _this->_elements[0][mid]) {
			return mid;
		}
		else if (Key_value(aKey) < _this->_elements[0][mid]) {
			right = mid - 1;
		}
		else if (Key_value(aKey) > _this->_elements[0][mid]) {
			left = mid + 1;
		}
	}
	return left;
}

Boolean SortedArrayList_positionUsingBinarySearchForSearch(SortedArrayDictionary* _this, Key* aKey)
{

	int left = 0;
	int right = _this->_size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (Key_value(aKey) == _this->_elements[0][mid]) {
			return mid;
		}
		else if (Key_value(aKey) < _this->_elements[0][mid]) {
			right = mid - 1;
		}
		else if (Key_value(aKey) > _this->_elements[0][mid]) {
			left = mid + 1;
		}
	}
	return FALSE;
}



void SortedArrayList_addAt(SortedArrayDictionary * _this, Key * aKey, Object * anObject, int aPosition)
{
	for (int i = _this->_size; i > aPosition; i--)
	{
		// ���� ���߾ �̵����Ѿ� �Ѵ�.
		_this->_elements[0][i] = _this->_elements[0][i-1];
		_this->_elements[1][i] = _this->_elements[1][i-1];
	}
	_this->_elements[0][aPosition] = Key_value(aKey); //Key��
	_this->_elements[1][aPosition] = Object_value(anObject);//Object��
	(_this->_size)++;
}


Boolean  SortedArrayDictionary_keyDoesExist(SortedArrayDictionary * _this, Key * aKey)
{
	return SortedArrayList_positionUsingBinarySearchForSearch(_this, aKey);
}

//������ ���������̹Ƿ� NULL�� ��ȯ�� ���� ������ �ʾ� ��ȯ������ *�� �����ϴ�.
Element SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary * _this, Key * aKey)
{
	int aPosition = -1;
	aPosition = SortedArrayList_positionUsingBinarySearch(_this, aKey);
	Element removedElement = _this->_elements[1][aPosition]; //Object ���� �����Ѵ�.
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[0][i - 1] = _this->_elements[0][i]; //�ش� Key�� �����ؾ� �Ѵ�.
		_this->_elements[1][i - 1] = _this->_elements[1][i]; //�ش� Object���� �����ؾ� �Ѵ�.
	}
	_this->_size--;
	return removedElement;
}

