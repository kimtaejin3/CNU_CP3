#include "common.h"

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
}MagicSquare;


Boolean MagicSquare_orderIsValid(MagicSquare *_this);
void MagicSquare_solve(MagicSquare *_this);
void MagicSquare_setOrder(MagicSquare* _this, int newOrder);
int MagicSquare_Order(MagicSquare* _this);
MagicSquare* MagicSquare_new();
void MagicSquare_delete(MagicSquare* _this);
int MagicSquare_cell(MagicSquare* _this, int aRow, int aCol);