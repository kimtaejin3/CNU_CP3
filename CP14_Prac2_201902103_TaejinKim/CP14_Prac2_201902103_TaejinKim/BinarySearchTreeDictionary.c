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
		// aKey �� Ʈ���� �̹� �����Ѵ� 
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
		else { // _root �� ������ Object �� ������ �ִ�. 
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
				// ������ Object �� ���� �ִ� _root �� ���� �ڽ� ��带 ��� ������ �ִ�. 
				// ���� Ʈ���� �ֿ��� ��带 ã�Ƽ� �����Ͽ� ��´�. 
				// �����Ͽ� ���� �ֿ��� ��尡 ���ο� ��Ʈ �̴�. 
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
	// �� ������ parent �� NULL �� �ƴϸ�, parent �� key ���� aKey �� ��ġ���� �ʴ´� 
	if (Key_compareTo(aKey, BinaryNode_key(parent)) < 0) {
		// ������ ���� ���� Ʈ������ ã�ƾ� �Ѵ� 
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {
			// �־��� aKey �� ���� ���Ұ� �������� �ʴ´�. 
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(leftChild)) == 0) {
			// leftChild�� ������ ����̴� 
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
				// �����ؾ� �ϴ� leftChild �� ���� �ڽĳ�带 ��� ������ �ִ�. 
				// leftChild�� ���� ��Ʈ������ �� ���� ��带 ã�Ƽ� ���ο� leftChild �� �Ѵ�. 
				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost); // rightmost �� �����Ǵ� leftChild �� ��ü��Ų��. 
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
	// ���⼭ rootOfSubtree �� ������ ��� (��, call �ϴ� ���� removedNode) �̴�. 
	// �� ������ rootOfSubtree �� ���� �ڽ� ��带 ��� ������ �ִ�. 
	// �츮�� rootOfSubtree �� left subtree ���� rightmost �� ã�� �����Ͽ� ���� �Ѵ�. 
	BinaryNode* leftOfRoot = BinaryNode_left(rootOfSubtree); BinaryNode* rightmost = leftOfRoot; // rightmost �� �ʱ�ȭ
	if (BinaryNode_right(leftOfRoot) == NULL) {
		// rightmost �� ã������ subtree �� right subtree �� �������� �ʴ´�
		// ���� �� subtree�� root �� rightmost �̴�. 
		BinaryNode_setLeft(rootOfSubtree, BinaryNode_left(leftOfRoot));
	}
	else {
		// rightmost �� ã������ subtree �� right subtree �� empty �� �ƴϴ�.
		BinaryNode* parentOfRightmost = NULL;
		do {
			// rightmost �� ã�Ƽ� ������ �Ʒ��� ��������.
			parentOfRightmost = rightmost; rightmost = BinaryNode_right(rightmost);
		} while (BinaryNode_right(rightmost) != NULL);
		BinaryNode_setRight(parentOfRightmost, BinaryNode_left(rightmost));
	} // �ֿ��� BinaryNode �� return �Ѵ�. 
	BinaryNode_setLeft(rightmost, NULL);   // �ʿ� ���� ���� left �� NULL �� �����. right �� �̹� NULL �̴�. 
	return  rightmost;
}


