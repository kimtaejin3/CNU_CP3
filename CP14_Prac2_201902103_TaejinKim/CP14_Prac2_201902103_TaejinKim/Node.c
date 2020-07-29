#include"Node.h"

struct _Node {
	Key* aKey;
	Object* anObject;
	Node* _next;
};

Node* Node_new() {
	Node* _this = NewObject(Node);
	return _this;
}

void Node_delete(Node* _this) {
	free(_this);
}

//void Node_setElement(Node* _this, Element newElement) {
//	_this->_element = newElement;
//}

void Node_setKey(Node* _this, Key* newKey)
{
	_this->aKey = newKey;
}

Key* Node_key(Node* _this)
{
	return _this->aKey;
}

Object* Node_object(Node* _this)
{
	return _this->anObject;
}

void Node_setObject(Node* _this, Object* newObject)
{
	_this->anObject = newObject;
}


void Node_setNext(Node* _this, Node* newNext) {
	_this->_next = newNext;
}

Node* Node_next(Node* _this) {
	return _this->_next;
}
