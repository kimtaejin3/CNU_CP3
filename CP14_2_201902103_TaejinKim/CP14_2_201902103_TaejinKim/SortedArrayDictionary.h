#include"Common.h"
#include"BinaryNode.h"

typedef Object Element;
typedef struct _SortedArrayDictionary SortedArrayDictionary;

SortedArrayDictionary* SortedArrayDictionary_new(int maxSize);
void  SortedArrayDictionary_delete(SortedArrayDictionary* _this);

Boolean  SortedArrayDictionary_isEmpty(SortedArrayDictionary* _this);
Boolean  SortedArrayDictionary_isFull(SortedArrayDictionary* _this);

int SortedArrayList_positionUsingBinarySearch(SortedArrayDictionary* _this, Key* aKey);
void SortedArrayList_addAt(SortedArrayDictionary* _this, Key* aKey, Object* anObject, int aPosition);


void  SortedArrayDictionary_addKeyAndObject(SortedArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean  SortedArrayDictionary_keyDoesExist(SortedArrayDictionary* _this, Key* aKey);
Element* SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary* _this, Key* aKey);

