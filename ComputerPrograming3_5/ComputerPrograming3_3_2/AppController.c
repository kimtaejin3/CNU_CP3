#include "AppController.h"
#include "common.h"
#include"AppView.h"
#include "MagicSquare.h"
//#include "Timer.h"
#include<stdio.h>
#define MAX_ORDER 99
#define END_OF_RUN -1

struct _AppController {
	int _nonsense;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_showBoard(AppController* _this, MagicSquare* aMagicSquare) {
	char messageBuffer[255];
	int order = MagicSquare_Order(aMagicSquare);
	sprintf_s(messageBuffer, sizeof(messageBuffer), "Magic Square Board: Order %2d\n", order);
	AppView_out(messageBuffer);
	AppView_out("    ");
	for (int col = 0; col < order; col++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", col);
		AppView_out(messageBuffer);
	}
	AppView_out("\n");
	for (int row = 0; row < order; row++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", row);
		AppView_out(messageBuffer);
		for (int col = 0; col < order; col++) {
			sprintf_s(messageBuffer, sizeof(messageBuffer), "%3d ", MagicSquare_cell(aMagicSquare, row, col));
			AppView_out(messageBuffer);
		}
		AppView_out("\n");
	}
}

void AppController_ShowOrderIsValid(MagicSquare* magicSquare)
{
	if (magicSquare->_order < 3) {
		AppView_out("����: ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ� �մϴ�.\n");
	}
	else if (magicSquare->_order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "����: ������ �ʹ� Ů�ϴ�. %d ���� �۾ƾ� �մϴ�.\n", MAX_ORDER);
		AppView_out(messageBuffer);
	}
	else if ((magicSquare->_order % 2 == 0)) {
		AppView_out("����: ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�. \n");
	}
}


void AppController_run(AppController* _this) {
	
	MagicSquare *magicSquare=MagicSquare_new();
	

	AppView_out("<<< ������ Ǯ�̸� �����մϴ� >>>\n");
	int inputOrder = AppView_in_order();// ������ ������ �Է� �޾� inputOrder�� ����
	while (inputOrder != END_OF_RUN) {//������ -1�̸� ���α׷� ����
		MagicSquare_setOrder(magicSquare, inputOrder);
		if (MagicSquare_orderIsValid(magicSquare)) {
			MagicSquare_solve(magicSquare);
			AppController_showBoard(_this, magicSquare);
		}
		else {
			AppController_ShowOrderIsValid(magicSquare);
		}
		inputOrder = AppView_in_order();//������ ������ �Է¹޾� inputOrder�� ����
	}
	MagicSquare_delete(magicSquare);
	AppView_out("<<< ������ Ǯ�̸� �����մϴ� >>>\n");

}


/*
void AppController_run(AppController *_this)
{
	MagicSquare* magicSquare;
	int order, count;
	Timer* timer;
	double executionTime;

	timer = Timer_new();
	AppView_out("<<< ������ Ǯ���� ���� ������ �����մϴ�>>>\n");
	AppView_out("�ϳ��� ������ ���� 100ȸ �ݺ� ������ �ð��� �����մϴ�.\n");

	for (order = 9; order <= MAX_ORDER; order += 10) {
		
		magicSquare = MagicSquare_new();
		Timer_start(timer);
		for (count = 0; count < 100; count++) {
			MagicSquare_setOrder(magicSquare, order);
			MagicSquare_solve(magicSquare);
		}
		Timer_stop(timer);
		MagicSquare_delete(magicSquare);
		executionTime = Timer_duration(timer);
		AppView_out_executionTime(order, executionTime);
	}
	Timer_delete(timer);
	AppView_out("<<< ���� ������ ��Ĩ�ϴ� >>>\n");
}
*/
void AppController_delete(AppController* _this) {
	free(_this);
}