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
	printf("\n��������� %f �Դϴ�.\n", anAverageScore);
}

void AppView_out_numberOfStudentsAboveAverage(int aNumber)
{
	printf("��� �̻��� �л��� ��� %d�� �Դϴ�.\n", aNumber);
}

void AppView_out_maxScore(int aMaxScore) {
	printf("�ְ����� %d�Դϴ�.\n", aMaxScore);
}
void AppView_out_minScore(int aMinScore)
{
	printf("�������� %d�Դϴ�.\n", aMinScore);
}
void AppView_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c ������ %d�� �Դϴ�.\n", aGrade, aCount);
}

void AppView_out_studentInfo(char*studentID,int aScore, char grade)
{
	printf("�й�:%s ����:%d ����:%c\n", studentID,aScore, grade);
}

void AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength)
{
	printf("[����] �й� %s�� ���̰� �ʹ� ��ϴ�. �ִ� %d �Դϴ�.\n", aStudentID, maxLength);
}

void AppView_out_msg_invalidScore(aScore)
{
	printf("[����] ������ 0���� �۰ų� 100���� Ŀ��, �������� ������ �ƴմϴ�.\n");
}

void AppView_in_studentID(char* aStudentID) {
	printf("\n- �й��� �Է��ϼ���: ");
	scanf("%s", aStudentID);
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

	printf("- ������ �Է��Ͻÿ�: ");
	
	scanf("%d", &input);
	return input;
}