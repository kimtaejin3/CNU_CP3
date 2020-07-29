#include"Message.h"
#include"SortedLinkedDictionary.h"
#include"UnsortedLinkedDictionary.h"
#include"UnsortedArrayDictionary.h"
#include"SortedArrayDictionary.h"
#include"BinarySearchTreeDictionary.h"
#include"AppView.h"
#include"Timer.h"
#include"ParameterSet.h"

typedef struct _AppController AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void AppController_generateTestDataByRandomNumbers(AppController* _this);

double AppController_timeForUnsortedLinkedDictionary_add(AppController* _this, UnsortedLinkedDictionary* aList, int aTestSize);

double AppController_timeForUnsortedArrayDictionary_add(AppController* _this, UnsortedArrayDictionary* aList, int aTestSize);

double AppController_timeForSortedLinkedDictionary_add(AppController* _this, SortedLinkedDictionary* aList, int aTestSize);

double AppController_timeForSortedArrayDictionary_add(AppController* _this, SortedArrayDictionary* aList, int aTestSize);
double AppController_timeForBinarySearchTree_add(AppController* _this, BinarySearchTreeDictionary* aList, int aTestSize);

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd,double aTimeForSearch, double aTimeForRemove);

double AppController_timeForUnsortedLinkedDictionary_search(AppController* _this, UnsortedLinkedDictionary* aList, int aTestSize);
double AppController_timeForUnsortedArrayDictionary_search(AppController* _this, UnsortedArrayDictionary* aList, int aTestSize);

double AppController_timeForSortedLinkedDictionary_search(AppController* _this, SortedLinkedDictionary* aList, int aTestSize);
double AppController_timeForSortedArrayDictionary_search(AppController* _this, SortedArrayDictionary* aList, int aTestSize);
double AppController_timeForBinarySearchTree_search(AppController* _this, BinarySearchTreeDictionary* aList, int aTestSize);


double AppController_timeForUnsortedLinkedDictionary_remove(AppController* _this, UnsortedLinkedDictionary* aList, int aTestSize);
double AppController_timeForUnsortedArrayDictionary_remove(AppController* _this, UnsortedArrayDictionary* aList, int aTestSize);

double AppController_timeForSortedLinkedDictionary_remove(AppController* _this, SortedLinkedDictionary* aList, int aTestSize);
double AppController_timeForSortedArrayDictionary_remove(AppController* _this, SortedArrayDictionary* aList, int aTestSize);
double AppController_timeForBinarySearchTree_remove(AppController* _this, BinarySearchTreeDictionary* aList, int aTestSize);









