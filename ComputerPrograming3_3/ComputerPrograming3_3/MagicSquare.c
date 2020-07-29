#include "MagicSquare.h"
#include "AppView.h"
#include<stdio.h>// only for sprintf()

typedef struct {
	int _row;
	int _col;
}CellLocation;

#define EMPTY_CELL -1
int row, col;

Boolean MagicSquare_orderIsValid(int anOrder)
{

	//모델과 뷰와 정보를 주고 받는 설계는 지양해야 함.
	if (anOrder < 3) {
		return FALSE;
	}
	else if (anOrder > MAX_ORDER) {
		return FALSE;
	}
	else if ((anOrder % 2 == 0)) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER])
{
	for (row = 0; row < anOrder; row++)
	{
		for (col = 0; col < anOrder; col++) {
			aBoard[row][col] = EMPTY_CELL;
		}
	}
	CellLocation currentLoc, nextLoc;
	currentLoc._row = 0;
	currentLoc._col = anOrder/2;
	
	int cellValue = 1;
	aBoard[currentLoc._row][currentLoc._col] = cellValue;

	int lastCellValue = anOrder * anOrder;
	for (cellValue = 2; cellValue <= lastCellValue; cellValue++)
	{// cellValue가 2부터 (anOrder * anOrder) 까지 1씩 증가하며 다음 내용을 반복 
	 // <현재위치>로부터 <다음 위치>를 계산한다 ;
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = anOrder - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= anOrder) {
			nextLoc._col = 0;
		}
		if (aBoard[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		aBoard[nextLoc._row][nextLoc._col] = cellValue;
		currentLoc = nextLoc;
	}
}
