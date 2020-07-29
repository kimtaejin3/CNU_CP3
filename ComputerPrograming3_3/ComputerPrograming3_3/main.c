#include "common.h"
#include"AppView.h"
#include "MagicSquare.h"
#include<stdio.h>
#define END_OF_RUN -1


void Main_showBoard(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER])
{
	char messageBuffer[255];

	sprintf_s(messageBuffer, sizeof(messageBuffer), "> Magic Square Board: Order %2d\n", anOrder);
	AppView_out(messageBuffer);
	AppView_out("    ");//��ĭ 4��

	for (int col = 0; col < anOrder; col++)
	{
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d] ", col);
		AppView_out(messageBuffer);
	}
	AppView_out("\n");
	for (int row = 0; row < anOrder; row++)
	{
		sprintf_s(messageBuffer, sizeof(messageBuffer),"[%2d] ", row);
		AppView_out(messageBuffer);
		for (int col = 0; col < anOrder; col++)
		{
			sprintf_s(messageBuffer, sizeof(messageBuffer), " %2d  ", aBoard[row][col]);
			AppView_out(messageBuffer);
		}
		AppView_out("\n");
	}
}

void Main_ShowOrderIsValid(int anOrder)
{
	if (anOrder < 3) {
		AppView_out("����: ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ� �մϴ�.\n");
	}
	else if (anOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "����: ������ �ʹ� Ů�ϴ�. %d ���� �۾ƾ� �մϴ�.\n", MAX_ORDER);
		AppView_out(messageBuffer);
	}
	else if ((anOrder % 2 == 0)) {
		AppView_out("����: ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�. \n");
	}
}

int main()
{
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];

	AppView_out("<<< ������ Ǯ�̸� �����մϴ� >>>\n");
	inputOrder = AppView_in_order();// ������ ������ �Է� �޾� inputOrder�� ����
	while (inputOrder != END_OF_RUN) {//������ -1�̸� ���α׷� ����
		if (MagicSquare_orderIsValid(inputOrder)) {
			MagicSquare_solve(inputOrder, board);
			Main_showBoard(inputOrder, board);//�������� ȭ�鿡 �����ش�.
		}
		else
		{
			Main_ShowOrderIsValid(inputOrder);
		}
		inputOrder = AppView_in_order();//������ ������ �Է¹޾� inputOrder�� ����
	}
	AppView_out("<<< ������ Ǯ�̸� �����մϴ� >>>\n");

	return 0;
}