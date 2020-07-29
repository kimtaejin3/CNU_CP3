#include"Common.h"
#include"BinaryNode.h"
#include"Traverse.h"


typedef struct _Dictionary Dictionary;

Dictionary* Dictionary_new(void);
void Dictionary_delete(Dictionary* _this);

Boolean Dictionary_isEmpty(Dictionary* _this);
Boolean Dictionary_isFull(Dictionary* _this);
int Dictionary_size(Dictionary* _this);

Boolean Dictionary_keyDoesExist(Dictionary* _this, Key* aKey);
Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey);

Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode* aNode);

Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode);
Boolean  Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject);
Boolean  Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);
Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey);
Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent);
BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfSubtree);
Boolean Dictionary_replaceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject);

void  Dictionary_scanInSortedOrder(Dictionary* _this, Traverse* aTraverse);
void Dictionary_inorderRecursively(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int depth);




