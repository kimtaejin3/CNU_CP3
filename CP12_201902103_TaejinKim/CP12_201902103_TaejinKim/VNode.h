#include"Common.h"
#include<stdlib.h>

typedef char ElementForVStack;

typedef struct _VNode VNode;


VNode* VNode_new();
void VNode_delete(VNode* _this);
void VNode_setElement(VNode* _this, ElementForVStack newElement);
ElementForVStack VNode_element(VNode* _this);
void VNode_setNext(VNode* _this, VNode* newNext);
VNode* VNode_next(VNode* _this);



