#include"SortedArrayDictionary.h"
#include<stdlib.h>

/*
	중요!
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
	// 제1단계: 삽입할 위치를 결정한다
	int positionForAdd = SortedArrayList_positionUsingBinarySearch(_this, aKey);
	// 제2단계: 찾아진 삽입 위치에 주어진 원소를 삽입한다
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
		// 쌍을 맞추어서 이동시켜야 한다.
		_this->_elements[0][i] = _this->_elements[0][i-1];
		_this->_elements[1][i] = _this->_elements[1][i-1];
	}
	_this->_elements[0][aPosition] = Key_value(aKey); //Key값
	_this->_elements[1][aPosition] = Object_value(anObject);//Object값
	(_this->_size)++;
}


Boolean  SortedArrayDictionary_keyDoesExist(SortedArrayDictionary * _this, Key * aKey)
{
	return SortedArrayList_positionUsingBinarySearchForSearch(_this, aKey);
}

//데이터 측정실험이므로 NULL를 반환할 일이 생기지 않아 반환형으로 *를 뺐습니다.
Element SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary * _this, Key * aKey)
{
	int aPosition = -1;
	aPosition = SortedArrayList_positionUsingBinarySearch(_this, aKey);
	Element removedElement = _this->_elements[1][aPosition]; //Object 값을 리턴한다.
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[0][i - 1] = _this->_elements[0][i]; //해당 Key를 삭제해야 한다.
		_this->_elements[1][i - 1] = _this->_elements[1][i]; //해당 Object또한 삭제해야 한다.
	}
	_this->_size--;
	return removedElement;
}

