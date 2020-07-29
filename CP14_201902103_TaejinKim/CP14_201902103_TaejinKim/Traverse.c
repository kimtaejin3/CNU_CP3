#include"Traverse.h"
#include<stdlib.h>
#include<stdio.h>

struct _Traverse {
	int nonMeaning;
};

Traverse* Traverse_new(void)
{
	Traverse* _this = NewObject(Traverse);
	return _this;
}

void Traverse_delete(Traverse* _this)
{
	free(_this);
}

void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int depth)
{
	char buffer[100];
	char keyValue=Key_value(aKey);
	//if (depth == 1) {
		//sprintf_s(buffer, sizeof(buffer), "%3s", " ");
		//AppView_out(buffer);
	//}
	if(depth!=1) {
		sprintf_s(buffer, sizeof(buffer), "%3s", " ");
		AppView_out(buffer);
	}
	for (int i = 1; i < depth; i++) {
		sprintf_s(buffer, sizeof(buffer), "%3s", " ");
		AppView_out(buffer);
	}
	sprintf_s(buffer, sizeof(buffer), "%c\n", keyValue);
	AppView_out(buffer);
}

