#include"Message.h"
#include"SortedLinkedList.h"
#include"UnsortedLinkedList.h"
#include"AppView.h"
#include"Timer.h"
#include"ParameterSet.h"

typedef struct _AppController AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void AppController_generateTestDataByRandomNumbers(AppController* _this);

double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize);

double AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* aList, int aTestSize);

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax);

double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize);

double AppController_timeForSortedLinkedList_min(AppController* _this, SortedLinkedList* aList, int aTestSize);

double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize);

double AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* aList, int aTestSize);







