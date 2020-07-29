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
		AppView_out("오류: 차수가 너무 작습니다. 3보다 크거나 같아야 합니다.\n");
	}
	else if (magicSquare->_order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "오류: 차수가 너무 큽니다. %d 보다 작아야 합니다.\n", MAX_ORDER);
		AppView_out(messageBuffer);
	}
	else if ((magicSquare->_order % 2 == 0)) {
		AppView_out("오류: 차수가 짝수입니다. 홀수이어야 합니다. \n");
	}
}


void AppController_run(AppController* _this) {
	
	MagicSquare *magicSquare=MagicSquare_new();
	

	AppView_out("<<< 마방진 풀이를 시작합니다 >>>\n");
	int inputOrder = AppView_in_order();// 마방진 차수를 입력 받아 inputOrder에 저장
	while (inputOrder != END_OF_RUN) {//차수가 -1이면 프로그램 종료
		MagicSquare_setOrder(magicSquare, inputOrder);
		if (MagicSquare_orderIsValid(magicSquare)) {
			MagicSquare_solve(magicSquare);
			AppController_showBoard(_this, magicSquare);
		}
		else {
			AppController_ShowOrderIsValid(magicSquare);
		}
		inputOrder = AppView_in_order();//마방진 차수를 입력받아 inputOrder에 저장
	}
	MagicSquare_delete(magicSquare);
	AppView_out("<<< 마방진 풀이를 종료합니다 >>>\n");

}


/*
void AppController_run(AppController *_this)
{
	MagicSquare* magicSquare;
	int order, count;
	Timer* timer;
	double executionTime;

	timer = Timer_new();
	AppView_out("<<< 마방진 풀이의 성능 측정을 시작합니다>>>\n");
	AppView_out("하나의 차수에 대해 100회 반복 실행한 시간을 측정합니다.\n");

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
	AppView_out("<<< 성능 측정을 마칩니다 >>>\n");
}
*/
void AppController_delete(AppController* _this) {
	free(_this);
}