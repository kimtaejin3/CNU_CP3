#include "Common.h"
#include<stdio.h>
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
	printf("최고점은 %d입니다.\n",aMaxScore);
}
void AppView_out_minScore(int aMinScore)
{
	printf("최저점은 %d입니다.\n",aMinScore);
}
void AppView_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c 학점은 %d명 입니다.\n", aGrade, aCount);
}

void AppView_out_studentInfo(int aScore, char grade)
{
	printf("점수:%d 학점:%c\n", aScore, grade);
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

	printf("\n- 점수를 입력하시오: ");
	scanf_s("%d", &input);
	return input;
}