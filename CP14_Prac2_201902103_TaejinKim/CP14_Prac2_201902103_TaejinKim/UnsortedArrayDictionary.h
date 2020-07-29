#include"Common.h"
#include"BinaryNode.h"


typedef struct _UnsortedArrayDictionary UnsortedArrayDictionary;

UnsortedArrayDictionary* UnsortedArrayDictionary_new(int maxSize);
void  UnsortedArrayDictionary_delete(UnsortedArrayDictionary* _this);
Boolean  UnsortedArrayDictionary_isEmpty(UnsortedArrayDictionary* _this);
Boolean  UnsortedArrayDictionary_isFull(UnsortedArrayDictionary* _this);
void  UnsortedArrayDictionary_addKeyAndObject(UnsortedArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean  UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary* _this, Key* aKey);
Element UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary* _this, Key* aKey);



