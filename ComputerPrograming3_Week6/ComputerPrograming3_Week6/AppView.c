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
	printf("\n��������� %f �Դϴ�.\n", anAverageScore);
}

void AppView_out_numberOfStudentsAboveAverage(int aNumber)
{
	printf("��� �̻��� �л��� ��� %d�� �Դϴ�.\n", aNumber);
}

void AppView_out_maxScore(int aMaxScore) {
	printf("�ְ����� %d�Դϴ�.\n",aMaxScore);
}
void AppView_out_minScore(int aMinScore)
{
	printf("�������� %d�Դϴ�.\n",aMinScore);
}
void AppView_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c ������ %d�� �Դϴ�.\n", aGrade, aCount);
}

void AppView_out_studentInfo(int aScore, char grade)
{
	printf("����:%d ����:%c\n", aScore, grade);
}

Boolean AppView_in_doesContinueToInputNextStudent() {

	char answer;
	printf("\n? ������ �Է��Ϸ��� 'Y'�� , �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�.");
	answer = getcharDirectlyFromKeyboard();
	
	return (answer == 'Y' || answer == 'y');

}

int AppView_in_score()
{
	int input;

	printf("\n- ������ �Է��Ͻÿ�: ");
	scanf_s("%d", &input);
	return input;
}