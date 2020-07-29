#include"AppController.h"
#include<time.h>
#include<stdio.h>
#define MIN_TEST_SIZE 1000
#define NUMBER_OF_TESTS 5
#define INTERVAL_SIZE 1000

struct _AppController {
	int* _testData;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this)
{
	AppView_out(MSG_StartPerformanceMeasuring);

	int numberOfTests = NUMBER_OF_TESTS;
	int intervalSize = INTERVAL_SIZE;
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);
	_this->_testData = NewVector(int, maxTestSize); // 유의: 사용을 종료한 후, 이것을 소멸시킬 위치는? 

	AppController_generateTestDataByRandomNumbers(_this);


	AppView_out(MSG_TitleForUnsortedLinkedList);

	int testSize = MIN_TEST_SIZE;

	for (int i = 0; i < numberOfTests; i++) {

		UnsortedLinkedList* listForTest = UnsortedLinkedList_new();
		double timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, listForTest, testSize);
		double timeForMin = AppController_timeForUnsortedLinkedList_min(_this, listForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForMin,timeForRemoveMax);
		UnsortedLinkedList_delete(listForTest);
		testSize += intervalSize;
	}
	AppView_out(MSG_EndPerformanceMeasuring);
}

void AppController_generateTestDataByRandomNumbers(AppController* _this) {
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxTestSize; i++) {
		_this->_testData[i] = rand();
	}
}

double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isFull(aList)) {
			UnsortedLinkedList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
	Element max;
	double duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) {
			max = UnsortedLinkedList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
	Element min;
	double duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) {
			min = UnsortedLinkedList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd,double aTimeFormin,double aTimeForRemoveMax)
{
	char results[255];
	sprintf_s(results, sizeof(results), "크기: %4d, 삽입: %6ld, 최솟값얻기:%7ld 최대값삭제: %7ld\n", aTestSize, (long)aTimeForAdd, (long)aTimeFormin,(long)aTimeForRemoveMax);
	AppView_out(results);
}


void AppController_delete(AppController* _this) {
	free(_this->_testData);
	free(_this);
}


