#include"Common.h"
#include"Key.h"
#include"Object.h"
#include"BinaryNode.h"

typedef int Element;
typedef struct _BinarySearchTreeDictionary BinarySearchTreeDictionary;

BinarySearchTreeDictionary* BinarySearchTreeDictionary_new(int maxSize);
void  BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this);
Boolean  BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this);
Boolean  BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary* _this);
void  BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject);
Boolean  BinarySearchTreeDictionary_keyDoesExist(BinarySearchTreeDictionary* _this, Key* aKey);
Element* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary* _this, Key* aKey);
Dictionary_deleteBinaryNodes(BinarySearchTreeDictionary* _this, BinaryNode* aNode);
void  BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this);
Object* Dictionary_searchTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* aNode)


