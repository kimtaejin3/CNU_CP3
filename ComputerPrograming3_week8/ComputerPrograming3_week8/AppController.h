#include"Message.h"
#include"UnSortedArrayList.h"
#include"SortedArrayList.h"
#include"AppView.h"
#include"Timer.h"
#include"ParameterSet.h"

typedef struct _AppController AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

void AppController_generateTestDataByRandomNumbers(AppController* _this);

double AppController_timeForUnsortedArrayList_add(AppController* _this, UnsortedArrayList* aList, int aTestSize);

double AppController_timeForUnSortedArrayList_removeMax(AppController* _this, UnsortedArrayList* aList, int aTestSize);

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax);

double AppController_timeForUnsortedArrayList_min(AppController* _this, UnsortedArrayList* aList, int aTestSize);

double AppController_timeForSortedArrayList_add(AppController* _this, SortedArrayList* aList, int aTestSize);

double AppController_timeForSortedArrayList_removeMax(AppController* _this, SortedArrayList* aList, int aTestSize);

double AppController_timeForSortedArrayList_min(AppController* _this, SortedArrayList* aList, int aTestSize);






