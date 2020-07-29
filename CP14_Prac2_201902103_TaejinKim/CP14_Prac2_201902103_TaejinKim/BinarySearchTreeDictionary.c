#include"BinarySearchTreeDictionary.h"
#include<stdlib.h>

struct _BinarySearchTreeDictionary {
	BinaryNode* _root;
	int _size;
};


BinarySearchTreeDictionary* BinarySearchTreeDictionary_new()
{
	BinarySearchTreeDictionary* _this = NewObject(BinarySearchTreeDictionary);
	_this->_root = NULL;
	_this->_size = 0;
	return _this;
}

void  BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this)
{
	Dictionary_deleteBinaryNodes(_this, _this->_root);
	free(_this);
}

void Dictionary_deleteBinaryNodes(BinarySearchTreeDictionary* _this, BinaryNode* aNode)
{
	if (aNode != NULL) {
		Dictionary_deleteBinaryNodes(_this, BinaryNode_left(aNode));
		Dictionary_deleteBinaryNodes(_this, BinaryNode_right(aNode));
		BinaryNode_delete(aNode);
	}
}

Boolean  BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this)
{
	return (_this->_root == NULL);
}

Boolean  BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary * _this)
{
	return FALSE;
}

Boolean  BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary * _this, Key* aKey, Object* anObject)
{
	if (_this->_root == NULL) {
		_this->_root = BinaryNode_newWith(aKey, anObject, NULL, NULL);
		_this->_size = 1; 
		return TRUE;
	}
	else {
		return  (Dictionary_addToTree(_this, aKey, anObject, _this->_root));
	}
}


Boolean  Dictionary_addToTree(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent)
{ // At this point, parent is not NULL 
	if (Key_compareTo(aKey, BinaryNode_key(parent)) < 0)
	{
		if (BinaryNode_left(parent) == NULL)
		{
			BinaryNode_setLeft(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			_this->_size++;
			return TRUE;
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_left(parent));
		}
	}
	else if (Key_compareTo(aKey, BinaryNode_key(parent)) > 0) {

		if (BinaryNode_right(parent) == NULL)
		{
			BinaryNode_setRight(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			_this->_size++;
			return(TRUE);
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_right(parent));
		}
	}
	else {
		// ( Key_compareTo (aKey, BinaryNode_key(parent)) == 0 ) 
		// aKey 가 트리에 이미 존재한다 
		return  (FALSE);
	}
}

Boolean  BinarySearchTreeDictionary_keyDoesExist(BinarySearchTreeDictionary * _this, Key * aKey)
{
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL);
}

Object* Dictionary_searchTreeRecursively(BinarySearchTreeDictionary * _this, Key * aKey, BinaryNode * aNode)
{
	if (aNode == NULL)return NULL;
	else {
		if (Key_compareTo(aKey, BinaryNode_key(aNode)) == 0) {
			return (BinaryNode_object(aNode));
		}
		else if (Key_compareTo(aKey, BinaryNode_key(aNode)) < 0) {
			return (Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_left(aNode)));
		}
		else {
			return (Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_right(aNode)));

		}
	}
}

Object* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary * _this, Key * aKey)
{
	if (BinarySearchTreeDictionary_isEmpty(_this)) { return  (NULL); }
	else {
		if (Key_compareTo(aKey, BinaryNode_key(_this->_root)) != 0) { return  (Dictionary_removeFromTreeRecursively(_this, aKey, _this->_root)); }
		else { // _root 가 삭제할 Object 를 가지고 있다. 
			BinaryNode* removedNode = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL)
			{
				_this->_root = BinaryNode_right(_this->_root);
			}
			else if (BinaryNode_right(_this->_root) == NULL)
			{
				_this->_root = BinaryNode_left(_this->_root);
			}
			else {
				// 삭제할 Object 를 갖고 있는 _root 는 양쪽 자식 노드를 모두 가지고 있다. 
				// 왼쪽 트리의 최우측 노드를 찾아서 삭제하여 얻는다. 
				// 삭제하여 얻은 최우측 노드가 새로운 루트 이다. 
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, _this->_root);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode)); 
				_this->_root = rightmost;
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return (removedObject);
		}
	}
}


Object* Dictionary_removeFromTreeRecursively(BinarySearchTreeDictionary * _this, Key * aKey, BinaryNode * parent)
{
	// 이 시점에 parent 는 NULL 이 아니며, parent 의 key 값은 aKey 와 일치하지 않는다 
	if (Key_compareTo(aKey, BinaryNode_key(parent)) < 0) {
		// 삭제할 노드는 왼쪽 트리에서 찾아야 한다 
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {
			// 주어진 aKey 를 갖는 원소가 존재하지 않는다. 
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(leftChild)) == 0) {
			// leftChild가 삭제할 노드이다 
			BinaryNode* removedNode = leftChild;
			if (BinaryNode_left(removedNode) == NULL)
			{
				BinaryNode_setLeft(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL)
			{
				BinaryNode_setLeft(parent, BinaryNode_left(removedNode));
			}
			else {
				// 삭제해야 하는 leftChild 는 양쪽 자식노드를 모두 가지고 있다. 
				// leftChild의 왼쪽 부트리에서 최 우측 노드를 찾아서 새로운 leftChild 로 한다. 
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost); // rightmost 로 삭제되는 leftChild 를 대체시킨다. 
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return  (removedObject);
		}
		else {
			return  (Dictionary_removeFromTreeRecursively(_this, aKey, leftChild));
		}
	}
	else {
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) {
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(rightChild)) == 0) {
			BinaryNode* removedNode = rightChild;
			if (BinaryNode_left(removedNode) == NULL)
			{
				BinaryNode_setRight(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL)
			{
				BinaryNode_setRight(parent, BinaryNode_left(removedNode));
			}
			else {
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setRight(parent, rightmost);
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return  (removedObject);
		}
		else {
			return  (Dictionary_removeFromTreeRecursively(_this, aKey, rightChild));
		}
	}
}

BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(BinarySearchTreeDictionary * _this, BinaryNode * rootOfSubtree)
{
	// 여기서 rootOfSubtree 는 삭제될 노드 (즉, call 하는 곳의 removedNode) 이다. 
	// 이 시점에 rootOfSubtree 는 양쪽 자식 노드를 모두 가지고 있다. 
	// 우리는 rootOfSubtree 의 left subtree 에서 rightmost 를 찾아 삭제하여 얻어야 한다. 
	BinaryNode* leftOfRoot = BinaryNode_left(rootOfSubtree); BinaryNode* rightmost = leftOfRoot; // rightmost 의 초기화
	if (BinaryNode_right(leftOfRoot) == NULL) {
		// rightmost 를 찾으려는 subtree 의 right subtree 가 존재하지 않는다
		// 따라서 이 subtree의 root 가 rightmost 이다. 
		BinaryNode_setLeft(rootOfSubtree, BinaryNode_left(leftOfRoot));
	}
	else {
		// rightmost 를 찾으려는 subtree 의 right subtree 가 empty 가 아니다.
		BinaryNode* parentOfRightmost = NULL;
		do {
			// rightmost 를 찾아서 오른쪽 아래로 내려간다.
			parentOfRightmost = rightmost; rightmost = BinaryNode_right(rightmost);
		} while (BinaryNode_right(rightmost) != NULL);
		BinaryNode_setRight(parentOfRightmost, BinaryNode_left(rightmost));
	} // 최우측 BinaryNode 를 return 한다. 
	BinaryNode_setLeft(rightmost, NULL);   // 필요 없는 값인 left 를 NULL 로 만든다. right 는 이미 NULL 이다. 
	return  rightmost;
}


