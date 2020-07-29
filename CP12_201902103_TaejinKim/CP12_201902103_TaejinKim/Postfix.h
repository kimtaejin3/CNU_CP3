#include"VStack.h"
#include"AppView.h"

typedef struct _Postfix Postfix;

Postfix* Postfix_new(int givenMaxNumberOfTokens);
void Postfix_delete(Postfix* _this);

void Postfix_showTokenAndStack(Postfix* _this, int aCurrentToken);
void Postfix_setExpression(Postfix* _this, char* anExpression);
int Postfix_evaluatedValue(Postfix* _this);
PostfixError Postfix_evaluate(Postfix* _this);


