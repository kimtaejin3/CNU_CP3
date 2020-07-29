#include"Common.h"
#include"VNode.h"

typedef struct _VStack VStack;


VStack* VStack_new();

Boolean VStack_push(VStack* _this, ElementForVStack anElement);

ElementForVStack VStack_pop(VStack* _this);

void VStack_delete(VStack* _this);

Boolean VStack_isEmpty(VStack* _this);

Boolean VStack_isFull(VStack* _this);

void VStack_reset(VStack* _this);

ElementForVStack VStack_elementAt(VStack* _this, int anOrder);

int VStack_size(VStack* _this);

void VStack_deleteLinkedChain(VStack* _this);

