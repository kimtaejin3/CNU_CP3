#include"UnSortedArrayList.h"
#include<stdlib.h>

struct _UnsortedArrayList {
	int _capacity;
	int _size;
	Element* _elements;
};


UnsortedArrayList* UnsortedArrayList_new(int givenCapacity)
{
	UnsortedArrayList* _this = NewObject(UnsortedArrayList);
	_this->_capacity = givenCapacity;
	_this->_elements = NewVector(Element, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void UnsortedArrayList_delete(UnsortedArrayList* _this)
{
	free(_this);
}

Boolean UnsortedArrayList_isEmpty(UnsortedArrayList* _this) {
	return (_this->_size == 0);
}

Boolean UnsortedArrayList_isFull(UnsortedArrayList * _this)
{
	return (_this->_size == _this->_capacity);
}

Boolean UnsortedArrayList_add(UnsortedArrayList * _this, Element anElement)
{
	if (UnsortedArrayList_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_elements[_this->_size] = anElement;
		(_this->_size)++;
		return TRUE;
	}

}

Element UnsortedArrayList_min(UnsortedArrayList* _this)
{
	int minPosition;
	minPosition = UnsortedArrayList_minPositionRecursively(_this, 0, _this->_size - 1);
	return _this->_elements[minPosition];
}

int UnsortedArrayList_minPositionRecursively(UnsortedArrayList * _this, int left, int right)
{
	if (left == right) {
		return left;
	}
	else {
		int mid = (left + right) / 2;
		int minPositionOfLeftPart = UnsortedArrayList_minPositionRecursively(_this, left, mid);
		int minPositionOfRightPart = UnsortedArrayList_minPositionRecursively(_this, mid + 1, right);
		if (_this->_elements[minPositionOfLeftPart] <= _this->_elements[minPositionOfRightPart]) {
			return minPositionOfLeftPart;
		}
		else {
			return minPositionOfRightPart;
		}
	}
}


Element UnsortedArrayList_removeMax(UnsortedArrayList * _this)
{
	int maxPosition;
	Element max;
	maxPosition = UnsortedArrayList_maxPositionRecursively(_this, 0, _this->_size - 1);
	max = UnsortedArrayList_removeAt(_this, maxPosition);
	return max;
}

int UnsortedArrayList_maxPositionRecursively(UnsortedArrayList * _this, int left, int right) {
	if (left == right) {
		return left;
	}
	else {
		int mid = (left + right) / 2;
		int maxPositionOfLeftPart = UnsortedArrayList_maxPositionRecursively(_this, left, mid);
		int maxPositionOfRightPart = UnsortedArrayList_maxPositionRecursively(_this, mid + 1, right);
		if (_this->_elements[maxPositionOfLeftPart] >= _this->_elements[maxPositionOfRightPart]) {
			return maxPositionOfLeftPart;
		}
		else {
			return maxPositionOfRightPart;
		}
	}
}
Element UnsortedArrayList_removeAt(UnsortedArrayList * _this, int aPosition)
{
	// aPosition �� ���� �ݵ�� _this->_size�� ������ �۾ƾ� �Ѵ�
	Element removedElement = _this->_elements[aPosition];
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[i - 1] = _this->_elements[i];
	}
	_this->_size--;
	return removedElement;
}


