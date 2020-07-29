#define MAX_NUMBER_OF_STUDENTS 100
#include "Common.h"
#include "AppController.h"
#include "AppView.h"
#include"Student.h"
#include<stdlib.h>


AppController* AppController_new(void)
{
	AppController* _this = NewObject(AppController);
	if (_this != NULL) {
		_this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
	}
	return _this;//��ü�� �Ҹ��� �����ڰ� å����.
}

void AppController_showStudentsSortedByScore(AppController* _this)
{
	AppView_out("\n�л����� ������ ����Դϴ�.\n\n");
	Student* student;
	for (int i = 0; i < Ban_size(_this->_ban); i++) {
		student = Ban_elementAt(_this->_ban, i);
		int score = Student_score(student);
		AppView_out_studentInfo(Student_studentID(student), score, Ban_scoreToGrade(score));
	}
}

void AppController_showStatistics(AppController* _this)
{
	// �� ������ ���� ó���� ����� Ban ��ü�� ������ �ִ�
	AppView_out_averageScore(Ban_averageScore(_this->_ban));

	AppView_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppView_out_maxScore(Ban_maxScore(_this->_ban));
	AppView_out_minScore(Ban_minScore(_this->_ban));
	AppView_out("\n");
	// ���� �� �л����� Ban ��ü�κ��� GradeCounter ��ü ���·� ��´�
	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);

	AppView_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppView_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppView_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppView_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppView_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter); // �� �̻� �ʿ� �����Ƿ� �Ҹ��Ų��
}

Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore)
{
	Boolean inputIsValid = TRUE;
	if (!Student_studentIDIsValid(aStudentID)) {
		AppView_out_msg_invalidStudentID(aStudentID, MAX_STUDENT_ID_LENGTH);
		inputIsValid = FALSE;
	}
	if (!Student_scoreIsValid(aScore)) {
		AppView_out_msg_invalidScore(aScore);
		inputIsValid = FALSE;
	}
	return inputIsValid;
}

Boolean AppController_inputAndStoreStudents(AppController* _this)
{
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;
	char studentID[100];
	Student* student;

	while (storingAStudentWasSuccessful && AppView_in_doesContinueToInputNextStudent())
	{
		AppView_in_studentID(studentID);
		score = AppView_in_score();

		if (AppController_inputIsValid(_this, studentID, score)) {
			student = Student_new(studentID, score);
			
			storingAStudentWasSuccessful = Ban_add(_this->_ban, student);
		}
	}
	AppView_out("\n�Է��� �����մϴ�.\n");
	return storingAStudentWasSuccessful;
}

void AppController_run(AppController* _this)
{
	AppView_out("<<<���� ó���� �����մϴ� >>>\n");


	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);

	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppView_out("[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.\n");
		}
		else {
			//��հ� ���̻��� �л���,�ְ���, ������ ���
			AppController_showStatistics(_this);

			Ban_sortStudentsByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
	else {
		AppView_out("[����] ������ ���������� ������� �ʾҽ��ϴ�.");
	}

	AppView_out("\n<<<���� ó���� �����մϴ� >>>\n");

}



void AppController_delete(AppController* _this) {
	Ban_delete(_this->_ban);
	free(_this);
}

