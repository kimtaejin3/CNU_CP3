#include "MagicSquare.h"
#include "AppView.h"
#include<stdio.h>// only for sprintf()


typedef struct {
	int _row;
	int _col;
}CellLocation;

#define EMPTY_CELL -1
int row, col;

void MagicSquare_setOrder(MagicSquare*_this,int newOrder)
{
	_this->_order = newOrder;
}

int MagicSquare_Order(MagicSquare* _this)
{
	return _this->_order;
}

MagicSquare* MagicSquare_new() {
	MagicSquare* _this;
	_this = NewObject(MagicSquare);
	return _this;
}
void MagicSquare_delete(MagicSquare* _this)
{
	free(_this);
}

int MagicSquare_cell(MagicSquare* _this, int aRow, int aCol) {
	
	// 위치가 정상
	if ((0 <= aRow && aRow < _this->_order) &&	(0 <= aCol && aCol < _this->_order))
	{ 
		return _this->_board[aRow][aCol];
	}
	else { // 위치가 정상 범위를 벗어났음
		return -1;
	}
}


void MagicSquare_solve(MagicSquare *_this)
{
	for (row = 0; row < _this->_order; row++)
	{
		for (col = 0; col < _this->_order; col++) {
			_this->_board[row][col] = EMPTY_CELL;
		}
	}

	CellLocation currentLoc, nextLoc;
	currentLoc._row = 0;
	currentLoc._col = _this->_order / 2;

	int cellValue = 1;

	_this->_board[currentLoc._row][currentLoc._col] = cellValue;

	int lastCellValue = _this->_order * _this->_order;

	for (cellValue = 2; cellValue <= lastCellValue; cellValue++)
	{// cellValue가 2부터 (anOrder * anOrder) 까지 1씩 증가하며 다음 내용을 반복 
	 // <현재위치>로부터 <다음 위치>를 계산한다 ;
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = _this->_order - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= _this->_order) {
			nextLoc._col = 0;
		}

		if (_this->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		_this->_board[nextLoc._row][nextLoc._col] = cellValue;
		currentLoc = nextLoc;
	}
}
