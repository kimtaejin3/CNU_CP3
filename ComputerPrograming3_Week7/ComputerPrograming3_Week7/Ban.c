#define DEFAULT_CAPACITY 100
#include "Common.h"
#include "Ban.h"

struct _Ban {
	int _capacity;
	int _size;
	Student** _elements;
	GradeCounter* _gradeCounter;
};



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

	if(_this!=NULL){
		_this->_capacity = DEFAULT_CAPACITY;
		_this->_size = 0;
		_this->_elements = NewVector(Student*, _this->_capacity);
	}

	return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity)
{
	Ban* _this = NewObject(Ban);
	
	if (_this != NULL) {
		_this->_capacity = givenCapacity;
		_this->_size = 0;
		_this->_elements = NewVector(Student*, _this->_capacity);
	}
	
	return _this;
}

void Ban_delete(Ban * _this)
{
	free(_this->_elements);
	free(_this);
}

int Ban_capacity(Ban * _this)
{
	return (_this->_capacity);
}

int Ban_size(Ban * _this)
{
	return (_this->_size);
}

Boolean Ban_isEmpty(Ban * _this)
{
	return (_this->_size == 0);
}

Boolean Ban_isFull(Ban * _this)
{
	return (_this->_size >= _this->_capacity);
}

Boolean Ban_add(Ban * _this, Student* aStudent)
{
	if (Ban_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_elements[_this->_size] = aStudent;
		_this->_size++;
		return TRUE;
	}
}

Student* Ban_elementAt(Ban * _this, int anOrder)
{
	if (anOrder >= _this->_size) {//0보다 작은 것도 표시해야 하지 않을까?
		return NULL;
	}
	else
	{
		return _this->_elements[anOrder];
	}
}

void Ban_sortStudentsByScore(Ban * _this)
{
	Ban_quickSort(_this);
}

void Ban_quickSort(Ban* _this) {
	int size = Ban_size(_this);
	if (size >= 2) {
		//최솟값의 위치
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (Student_score(_this->_elements[i])<Student_score(_this->_elements[minPosition])) {
				minPosition = i;
			}
		}
		SWAP(Student*, _this->_elements[minPosition], _this->_elements[size - 1]);
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}

void Ban_quickSortRecursively(Ban * _this, int left, int right)
{
	if (left < right) {
		int mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid - 1);
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}

int Ban_partition(Ban * _this, int left, int right)
{
	int pivot = left;
	int pivotScore = Student_score(_this->_elements[pivot]);
	int toLeft = right + 1;
	int toRight = left;

	do {
		do { toRight++; } while (Student_score(_this->_elements[toRight])>pivotScore);
		do { toLeft--; } while (Student_score(_this->_elements[toLeft]) < pivotScore);

		if (toRight < toLeft) { SWAP(Student*, _this->_elements[toLeft], _this->_elements[toRight]); }
		
	} while (toRight < toLeft);
	SWAP(Student*, _this->_elements[pivot], _this->_elements[toLeft]);
	return toLeft;
}

int Ban_minScore(Ban * _this)
{
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}

int Ban_maxScore(Ban * _this)
{
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}

float Ban_averageScore(Ban * _this)
{
	float  sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size - 1);
	float  average = sumOfScores / (float)_this->_size;
	return average;
}

int Ban_sumOfScoresRecursively(Ban * _this, int left, int right) {

	if (left > right) {
		return 0;
	}
	else {
		int score = Student_score(_this->_elements[left]);
		return (score + Ban_sumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_maxScoreRecursively(Ban * _this, int left, int right)
{
	int mid;
	int maxOfLeftPart;
	int maxOfRightPart;
	if (left == right) {
		return Student_score(_this->_elements[left]);
	}
	else {
		mid = (left + right) / 2;
		maxOfLeftPart = Ban_maxScoreRecursively(_this, left, mid);
		maxOfRightPart = Ban_maxScoreRecursively(_this, mid + 1, right);
		if (maxOfLeftPart >= maxOfRightPart) {
			return maxOfLeftPart;
		}
		else {
			return maxOfRightPart;
		}
	}
}

int Ban_minScoreRecursively(Ban * _this, int left, int right)
{
	int min;
	if (left == right) {
		return Student_score(_this->_elements[left]);
	}
	else {
		min = Ban_minScoreRecursively(_this, left + 1, right);
		if (Student_score(_this->_elements[left]) <= min) {
			return Student_score(_this->_elements[left]);
		}
		else {
			return min;
		}
	}
}

int  Ban_numberOfStudentsAboveAverage(Ban * _this) {

	float average = Ban_averageScore(_this);
	int score;
	int numberOfStudentsAboveAverage = 0;

	for (int i = 0; i < _this->_size; i++) {
		
		score = Student_score(_this->_elements[i]);
		if ((float)score >= average)
		{
			numberOfStudentsAboveAverage++;
		}
	}
	return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_countGrades(Ban * _this) {

	char  currentGrade;
	int score;
	GradeCounter* gradeCounter = GradeCounter_new();

	for (int i = 0; i < _this->_size; i++) {
		score = Student_score(_this->_elements[i]);
		currentGrade = Ban_scoreToGrade(score);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return  gradeCounter;
}

