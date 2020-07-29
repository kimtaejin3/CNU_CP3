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
	AppView_out("    ");//빈칸 4개

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
		AppView_out("오류: 차수가 너무 작습니다. 3보다 크거나 같아야 합니다.\n");
	}
	else if (anOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "오류: 차수가 너무 큽니다. %d 보다 작아야 합니다.\n", MAX_ORDER);
		AppView_out(messageBuffer);
	}
	else if ((anOrder % 2 == 0)) {
		AppView_out("오류: 차수가 짝수입니다. 홀수이어야 합니다. \n");
	}
}

int main()
{
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];

	AppView_out("<<< 마방진 풀이를 시작합니다 >>>\n");
	inputOrder = AppView_in_order();// 마방진 차수를 입력 받아 inputOrder에 저장
	while (inputOrder != END_OF_RUN) {//차수가 -1이면 프로그램 종료
		if (MagicSquare_orderIsValid(inputOrder)) {
			MagicSquare_solve(inputOrder, board);
			Main_showBoard(inputOrder, board);//마방진을 화면에 보여준다.
		}
		else
		{
			Main_ShowOrderIsValid(inputOrder);
		}
		inputOrder = AppView_in_order();//마방진 차수를 입력받아 inputOrder에 저장
	}
	AppView_out("<<< 마방진 풀이를 종료합니다 >>>\n");

	return 0;
}