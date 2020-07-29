#define _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>

char getcharDirectlyFromKeyboard(void) {
	char  charFromKeyboard;
	charFromKeyboard = _getch();
	return  charFromKeyboard;
}


void AppView_out(char* s) {
	printf("%s", s);
}

void AppView_out_averageScore(float anAverageScore)
{
	printf("\n평균점수는 %f 입니다.\n", anAverageScore);
}

void AppView_out_numberOfStudentsAboveAverage(int aNumber)
{
	printf("평균 이상인 학생은 모두 %d명 입니다.\n", aNumber);
}

void AppView_out_maxScore(int aMaxScore) {
	printf("최고점은 %d입니다.\n", aMaxScore);
}
void AppView_out_minScore(int aMinScore)
{
	printf("최저점은 %d입니다.\n", aMinScore);
}
void AppView_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c 학점은 %d명 입니다.\n", aGrade, aCount);
}

void AppView_out_studentInfo(char*studentID,int aScore, char grade)
{
	printf("학번:%s 점수:%d 학점:%c\n", studentID,aScore, grade);
}

void AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength)
{
	printf("[오류] 학번 %s의 길이가 너무 깁니다. 최대 %d 입니다.\n", aStudentID, maxLength);
}

void AppView_out_msg_invalidScore(aScore)
{
	printf("[오류] 성적이 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다.\n");
}

void AppView_in_studentID(char* aStudentID) {
	printf("\n- 학번을 입력하세요: ");
	scanf("%s", aStudentID);
}

Boolean AppView_in_doesContinueToInputNextStudent() {

	char answer;
	printf("\n? 성적을 입력하려면 'Y'를 , 입력을 종료하려면 다른 아무 키나 치시오.");
	answer = getcharDirectlyFromKeyboard();

	return (answer == 'Y' || answer == 'y');

}

int AppView_in_score()
{
	int input;

	printf("- 점수를 입력하시오: ");
	
	scanf("%d", &input);
	return input;
}