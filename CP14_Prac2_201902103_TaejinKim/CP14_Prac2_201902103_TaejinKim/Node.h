#include"Common.h"
#include<stdlib.h>
#include"Key.h"
#include"Object.h"

typedef int Element;

typedef struct _Node Node;


Node* Node_new();
void Node_delete(Node* _this);
//void Node_setElement(Node* _this, Element newElement);
//Element Node_element(Node* _this);
void Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);
void Node_setKey(Node* _this, Key* newKey);
void Node_setObject(Node* _this, Object* newObject);
Key* Node_key(Node* _this);
Object* Node_object(Node* _this);


