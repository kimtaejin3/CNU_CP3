#include"Common.h"
#include"BinaryNode.h"
#include"AppView.h"

typedef struct _Traverse Traverse;

Traverse* Traverse_new(void);
void Traverse_delete(Traverse* _this);
void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int depth);
