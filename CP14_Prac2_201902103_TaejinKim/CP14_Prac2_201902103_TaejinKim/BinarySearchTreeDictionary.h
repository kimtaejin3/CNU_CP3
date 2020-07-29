#include"Common.h"
#include"Key.h"
#include"Object.h"
#include"BinaryNode.h"

typedef struct _BinarySearchTreeDictionary BinarySearchTreeDictionary;

BinarySearchTreeDictionary* BinarySearchTreeDictionary_new();
void  BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this);
Boolean  BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this);
Boolean  BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary* _this);
Boolean  BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject);
Boolean  BinarySearchTreeDictionary_keyDoesExist(BinarySearchTreeDictionary* _this, Key* aKey);
Object* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary* _this, Key* aKey);
Object* Dictionary_removeFromTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* parent);
BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(BinarySearchTreeDictionary* _this, BinaryNode* rootOfSubtree);

void Dictionary_deleteBinaryNodes(BinarySearchTreeDictionary* _this, BinaryNode* aNode);
void  BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this);
Object* Dictionary_searchTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* aNode);
Boolean  Dictionary_addToTree(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);


