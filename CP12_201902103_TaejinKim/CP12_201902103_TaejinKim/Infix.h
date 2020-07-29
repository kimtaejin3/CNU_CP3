#include"OStack.h"
#include"AppView.h"


typedef struct _Infix Infix;

Infix* Infix_new();
void  Infix_delete(Infix* _this);
Boolean  Infix_toPostfix(Infix* _this);
void Infix_setExpression(Infix* _this, char* newExpression);
char* Infix_postfix(Infix* _this);
void Infix_showTokenAndStack(Infix* _this, char aCurrentToken);
int  Infix_inComingPrecedence(char aToken);
int  Infix_inStackPrecedence(char aToken);



