#include"UnsortedArrayDictionary.h"
#include<stdlib.h>


/*
	중요!
	0 < i < n
	Key -> _elements[0][i]
	Object -> _elements[1][i]
*/

struct _UnsortedArrayDictionary {
	int _capacity;
	int _size;
	Element** _elements;
};

UnsortedArrayDictionary* UnsortedArrayDictionary_new(int maxSize)
{
	UnsortedArrayDictionary* _this = NewObject(UnsortedArrayDictionary);
	_this->_capacity = maxSize;
	_this->_elements = NewToDimensionVector(int, 2);
	for (int i = 0; i < 2; i++)
	{
		_this->_elements[i] = NewVector(int, maxSize);
	}
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

Boolean UnsortedArrayDictionary_isFull(UnsortedArrayDictionary * _this)
{
	return (_this->_size == _this->_capacity);
}

void UnsortedArrayDictionary_addKeyAndObject(UnsortedArrayDictionary * _this, Key * aKey, Object * anObject)
{
	_this->_elements[0][_this->_size] = Key_value(aKey);
	_this->_elements[1][_this->_size] = Object_value(anObject);
	(_this->_size)++;
}

Boolean  UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary * _this, Key * aKey)
{
	for (int i = 0; i < _this->_size; i++) {
		if (_this->_elements[0][i] == Key_value(aKey)) {
			return TRUE;
		}
	}
	return FALSE;
}

//데이터 측정실험이므로 NULL를 반환할 일이 생기지 않아 반환형으로 *를 뺐습니다.
Element UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary * _this, Key * aKey)
{
	int aPosition = -1;
	for (int i = 0; i < _this->_size; i++) {
		if (_this->_elements[0][i] == Key_value(aKey)) {
			aPosition = i;
		}
	}
	Element removedElement = _this->_elements[1][aPosition]; //Object 값 리턴
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[0][i - 1] = _this->_elements[0][i]; //Key 값 체인지 
		_this->_elements[1][i - 1] = _this->_elements[1][i]; //Object값 체인지
	}
	_this->_size--;
	return removedElement;
}


