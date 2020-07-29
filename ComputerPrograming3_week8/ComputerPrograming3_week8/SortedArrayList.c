#include"SortedArrayList.h"
#include<stdlib.h>

struct _SortedArrayList {
	int _capacity;
	int _size;
	Element* _elements;
};


SortedArrayList* SortedArrayList_new(int givenCapacity)
{
	SortedArrayList* _this = NewObject(SortedArrayList);
	_this->_capacity = givenCapacity;
	_this->_elements = NewVector(Element, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void SortedArrayList_delete(SortedArrayList* _this)
{
	free(_this);
}

Boolean SortedArrayList_isEmpty(SortedArrayList* _this) {
	return (_this->_size == 0);
}

Boolean SortedArrayList_isFull(SortedArrayList * _this)
{
	return (_this->_size == _this->_capacity);
}

Boolean SortedArrayList_add(SortedArrayList* _this, Element anElement)
{
	if (SortedArrayList_isFull(_this)) {
		return FALSE;
	}
	else {
		// ��1�ܰ�: ������ ��ġ�� �����Ѵ�
		int positionForAdd = SortedArrayList_positionUsingBinarySearch(_this, anElement);
		// ��2�ܰ�: ã���� ���� ��ġ�� �־��� ���Ҹ� �����Ѵ�
		SortedArrayList_addAt(_this, anElement, positionForAdd);
		return TRUE;
	}
}

int SortedArrayList_positionUsingBinarySearch(SortedArrayList* _this, Element anElement)
{
	
	int left = 0;
	int right = _this->_size - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (anElement == _this->_elements[mid]) {
			return mid;
		}
		else if (anElement < _this->_elements[mid]) {
			right = mid - 1;
		}
		else if (anElement > _this->_elements[mid]) {
			left = mid + 1;
		}
	}
	return left;
}

void SortedArrayList_addAt(SortedArrayList* _this, Element anElement, int aPosition)
{
	for (int i = aPosition; i < _this->_size-1; i++)
	{
		_this->_elements[i + 1] = _this->_elements[i];
	}
	_this->_elements[aPosition] = anElement;
	(_this->_size)++;
}

Element SortedArrayList_min(SortedArrayList* _this)
{
	int min;
	min = _this->_elements[0]; //�ּڰ��� ��ġ�� 0�̴�.
	return min;
}

Element SortedArrayList_removeMax(SortedArrayList* _this) {
	int maxPosition;
	Element max;
	maxPosition = _this->_size-1;
	max = SortedArrayList_removeAt(_this, maxPosition);
	return max;
}

Element SortedArrayList_removeAt(SortedArrayList* _this, int aPosition)
{
	
	Element removedElement = _this->_elements[aPosition];
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[i - 1] = _this->_elements[i];
	}
	_this->_size--;
	return removedElement;
}
