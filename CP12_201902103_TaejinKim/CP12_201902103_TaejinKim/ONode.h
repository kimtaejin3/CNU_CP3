#include"Common.h"
#include<stdlib.h>

typedef char ElementForOStack;

typedef struct _ONode ONode;


ONode* ONode_new();
void ONode_delete(ONode* _this);
void ONode_setElement(ONode* _this, ElementForOStack newElement);
ElementForOStack ONode_element(ONode* _this);
void ONode_setNext(ONode* _this, ONode* newNext);
ONode* ONode_next(ONode* _this);




