#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include"Student.h"

struct _Student {
	char _studentID[MAX_STUDENT_ID_LENGTH + 1];
	int _score;
};


Student* Student_new(char* givenStudentID, int givenScore)
{
	Student* _this = NewObject(Student);
	if (_this != NULL) {
		strcpy(_this->_studentID, givenStudentID);
		_this->_score = givenScore;
	}
	return _this;
}

void Student_delete(Student* _this) {
	free(_this);
}

char* Student_studentID(Student* _this) {
	char* copidStudentID = NewVector(char, 10);
	strcpy(copidStudentID, _this->_studentID);
	return copidStudentID;
}

int Student_score(Student* _this) {
	return _this->_score;
}

Boolean Student_studentIDIsValid(char* aStudentID)
{
	int length = 0;
	while (*aStudentID != '\0') {
		length++;
		aStudentID++;
	}
	return(length <= MAX_STUDENT_ID_LENGTH);
}

Boolean Student_scoreIsValid(int aScore)
{
	return (aScore >= 0 && aScore <= 100);
}