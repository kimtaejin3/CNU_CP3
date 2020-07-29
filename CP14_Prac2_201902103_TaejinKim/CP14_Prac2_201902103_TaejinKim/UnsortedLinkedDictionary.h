#include"Common.h"
#include"Node.h"
#include"Key.h"
#include"Object.h"

typedef struct _UnsortedLinkedDictionary UnsortedLinkedDictionary;

UnsortedLinkedDictionary* UnsortedLinkedDictionary_new();
void  UnsortedLinkedDictionary_delete(UnsortedLinkedDictionary* _this);
Boolean UnsortedLinkedDictionary_isEmpty(UnsortedLinkedDictionary* _this);
Boolean  UnsortedLinkedDictionary_isFull(UnsortedLinkedDictionary* _this);
void  UnsortedLinkedDictionary_addKeyAndObject(UnsortedLinkedDictionary* _this, Key* aKey, Object* anObject);
Boolean UnsortedLinkedDictionary_keyDoesExist(UnsortedLinkedDictionary* _this, Key* aKey);
Element* UnsortedLinkedDictionary_removeObjectForKey(UnsortedLinkedDictionary* _this, Key* aKey);

