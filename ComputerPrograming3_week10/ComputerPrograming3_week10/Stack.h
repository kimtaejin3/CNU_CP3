#include"Common.h"


typedef struct _Stack Stack;
typedef int Element;

Stack* Stack_new(int givenCapacity);

Boolean Stack_push(Stack* _this, int anOperand);

Element Stack_pop(Stack* _this);

void Stack_delete(Stack* _this);

Boolean Stack_isEmpty(Stack*_this);

Boolean Stack_isFull(Stack*_this);

void Stack_reset(Stack* _this);

Element Stack_elementAt(Stack* _this, int anOrder);

int Stack_size(Stack* _this);
