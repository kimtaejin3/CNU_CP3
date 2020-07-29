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
	return _this;//객체의 소멸은 생성자가 책임짐.
}

void AppController_showStudentsSortedByScore(AppController* _this)
{
	AppView_out("\n학생들의 성적순 목록입니다.\n\n");
	Student* student;
	for (int i = 0; i < Ban_size(_this->_ban); i++) {
		student = Ban_elementAt(_this->_ban, i);
		int score = Student_score(student);
		AppView_out_studentInfo(Student_studentID(student), score, Ban_scoreToGrade(score));
	}
}

void AppController_showStatistics(AppController* _this)
{
	// 이 시점에 성적 처리된 결과를 Ban 객체가 가지고 있다
	AppView_out_averageScore(Ban_averageScore(_this->_ban));

	AppView_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppView_out_maxScore(Ban_maxScore(_this->_ban));
	AppView_out_minScore(Ban_minScore(_this->_ban));
	AppView_out("\n");
	// 학점 별 학생수는 Ban 객체로부터 GradeCounter 객체 형태로 얻는다
	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);

	AppView_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppView_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppView_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppView_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppView_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter); // 더 이상 필요 없으므로 소멸시킨다
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
	AppView_out("\n입력을 종료합니다.\n");
	return storingAStudentWasSuccessful;
}

void AppController_run(AppController* _this)
{
	AppView_out("<<<성적 처리를 시작합니다 >>>\n");


	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);

	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppView_out("[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
		}
		else {
			//평균과 평군이상인 학생수,최고점, 최저점 출력
			AppController_showStatistics(_this);

			Ban_sortStudentsByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
	else {
		AppView_out("[오류] 성적이 정상적으로 저장되지 않았습니다.");
	}

	AppView_out("\n<<<성적 처리를 종료합니다 >>>\n");

}



void AppController_delete(AppController* _this) {
	Ban_delete(_this->_ban);
	free(_this);
}

