#define DEFAULT_CAPACITY 100
#include "Common.h"
#include "Ban.h"
#include<stdlib.h>

Boolean Ban_scoreIsValid(int aScore)
{
	return (aScore >= 0 && aScore <= 100);
}

char Ban_scoreToGrade(int aScore)
{
	if (aScore >= 90) {
		return 'A';
	}
	else if (aScore >= 80) {
		return 'B';
	}
	else if (aScore >= 70) {
		return 'C';
	}
	else if (aScore >= 60) {
		return 'D';
	}
	else {
		return 'F';
	}
}

Ban* Ban_new(void)
{
	Ban* _this = NewObject(Ban);

	_this->_capacity = DEFAULT_CAPACITY;
	_this->_size = 0;
	_this->_elements = NewVector(int, _this->_capacity);
	
	return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity)
{
	Ban* _this = NewObject(Ban);
	_this->_capacity = givenCapacity;
	_this->_size = 0;
	_this->_elements = NewVector(int, _this->_capacity);
	return _this;
}

void Ban_delete(Ban* _this)
{
	free(_this->_elements);
	free(_this);
}

int Ban_capacity(Ban* _this)
{
	return (_this->_capacity);
}

int Ban_size(Ban* _this)
{
	return (_this->_size);
}

Boolean Ban_isEmpty(Ban* _this)
{
	return (_this->_size == 0);
}

Boolean Ban_isFull(Ban* _this)
{
	return (_this->_size >= _this->_capacity);
}

Boolean Ban_add(Ban* _this, int aScore)
{
	if (Ban_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_elements[_this->_size] = aScore;
		_this->_size++;
		return TRUE;
	}
}

int Ban_elementAt(Ban* _this, int anOrder)
{
	if (anOrder >= _this->_size) {//0보다 작은 것도 표시해야 하지 않을까?
		return -1;
	}
	else
	{
		return _this->_elements[anOrder];
	}
}

void Ban_sortStudentsByScore(Ban* _this)
{
	int size = _this->_size;
	if (size >= 2) {
		//최솟값의 위치
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (_this->_elements[i] < _this->_elements[minPosition]) {
				minPosition = i;
			}
		}
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]);
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}

void Ban_quickSortRecursively(Ban* _this, int left, int right)
{
	if (left < right) {
		int mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid - 1);
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}

int Ban_partition(Ban* _this, int left, int right)
{
	int pivot = left;
	int pivotScore = _this->_elements[pivot];

	right++;
	do {
		do { left++; } while (_this->_elements[left] > pivotScore);
		do { right--; } while (_this->_elements[right] < pivotScore); if (left < right) { SWAP(int, _this->_elements[left], _this->_elements[right]); }
		if (left < right) 
		{
			SWAP(int, _this->_elements[left], _this->_elements[right]); 
		}
	} while (left < right);
	SWAP(int, _this->_elements[pivot], _this->_elements[right]);
	return right;
}

int Ban_minScore(Ban* _this)
{
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}

int Ban_maxScore(Ban* _this)
{
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}

float Ban_averageScore(Ban* _this)
{
	float  sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size - 1);
	float  average = sumOfScores / (float)_this->_size; 
	return average;
}

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right) {

	if (left > right) {
		return 0;
	}
	else {
		return (_this->_elements[left] + Ban_sumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_maxScoreRecursively(Ban* _this,int left, int right)
{
	int mid;
	int maxOfLeftPart;
	int maxOfRightPart;
	if (left == right) {
		return _this->_elements[left];
	}
	else {
		mid = (left+right)/2;
		maxOfLeftPart = Ban_maxScoreRecursively(_this, left, mid);
		maxOfRightPart = Ban_maxScoreRecursively(_this, mid + 1, right);
		if (maxOfLeftPart>=maxOfRightPart){
			return maxOfLeftPart;
		}
		else {
			return maxOfRightPart;
		}
	}
}

int Ban_minScoreRecursively(Ban* _this, int left, int right)
{
	int min;
	if (left == right) {
		return _this->_elements[left];
	}
	else {
		min = Ban_minScoreRecursively(_this, left + 1, right);
		if (_this->_elements[left] <= min) {
			return _this->_elements[left];
		}
		else {
			return min;
		}
	}
}

int  Ban_numberOfStudentsAboveAverage(Ban* _this) {

	float average = Ban_averageScore(_this); 

	int numberOfStudentsAboveAverage = 0;
	for (int i = 0; i < _this->_size; i++) { 
		if (((float)_this->_elements[i]) >= average) 
		{ 
			numberOfStudentsAboveAverage++; 
		} 
	} 
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_countGrades(Ban* _this) {
	char  currentGrade; 
	GradeCounter* gradeCounter = GradeCounter_new();
	
	for (int i = 0; i < _this->_size; i++) { 
		currentGrade = Ban_scoreToGrade(_this->_elements[i]); 
		GradeCounter_count(gradeCounter, currentGrade); 
	} 
	return  gradeCounter;
}

