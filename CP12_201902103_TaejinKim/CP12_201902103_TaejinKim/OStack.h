#include"Common.h"
#include"ONode.h"

typedef struct _OStack OStack;


OStack* OStack_new();

Boolean OStack_push(OStack* _this, ElementForOStack anElement);

ElementForOStack OStack_pop(OStack* _this);

void OStack_delete(OStack* _this);

Boolean OStack_isEmpty(OStack* _this);

Boolean OStack_isFull(OStack* _this);

void OStack_reset(OStack* _this);

ElementForOStack OStack_elementAt(OStack* _this, int anOrder);

int OStack_size(OStack* _this);

ElementForOStack OStack_topElement(OStack* _this);

void OStack_deleteLinkedChain(OStack* _this);
