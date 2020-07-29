#include"Common.h"

typedef struct _Queue Queue;
typedef char Element;

Queue* Queue_new(int givenCapacity);
void Queue_delete(Queue* _this);
Boolean Queue_isEmpty(Queue* _this);
Boolean Queue_isFull(Queue* _this);
int Queue_size(Queue* _this);
Element Queue_Front(Queue* _this);
Element Queue_elementAt(Queue* _this, int anOrder);

Boolean Queue_add(Queue* _this, Element anElement);
Element Queue_remove(Queue* _this);


