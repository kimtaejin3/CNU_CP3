#include"AppController.h"
#include<stdio.h>
#include<time.h>
#define MIN_TEST_SIZE 1000
#define NUMBER_OF_TESTS 5
#define INTERVAL_SIZE 1000

struct _AppController {
	int* _testData;
	ParameterSet* _parameterSet;
};

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	_this->_parameterSet = ParameterSet_new();
	return _this;
}

void AppController_initPerformanceMeasurement(AppController* _this) {
	ParameterSet_setMinTestSize(_this->_parameterSet, MIN_TEST_SIZE);
	ParameterSet_setIntervalSize(_this->_parameterSet, INTERVAL_SIZE);
	ParameterSet_setNumberOfTests(_this->_parameterSet, NUMBER_OF_TESTS);
	_this->_testData = NewVector(int, ParameterSet_maxTestSize(_this->_parameterSet));
	// 유의: 사용을 종료한 후, 이것을 소멸시킬 위치는?

	AppController_generateTestDataByRandomNumbers(_this);
}


void AppController_run(AppController* _this)
{
	AppView_out(MSG_StartPerformanceMeasuring);
	AppController_initPerformanceMeasurement(_this);

	int numberOfTests = ParameterSet_numberOfTests(_this->_parameterSet);
	int intervalSize = ParameterSet_intervalSize(_this->_parameterSet);
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);


	AppView_out(MSG_TitleForUnsortedArrayList);

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		UnsortedLinkedDictionary* listForTest = UnsortedLinkedDictionary_new();
		double timeForAdd = AppController_timeForUnsortedLinkedDictionary_add(_this, listForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd);
		UnsortedLinkedDictionary_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out(MSG_TitleForSortedArrayList);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		SortedLinkedDictionary* listForTest = SortedLinkedDictionary_new();
		double timeForAdd = AppController_timeForSortedLinkedDictionary_add(_this, listForTest, testSize);
		
		AppController_showResults(_this, testSize, timeForAdd);
		SortedLinkedDictionary_delete(listForTest);
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


double AppController_timeForUnsortedLinkedDictionary_add(AppController* _this, UnsortedLinkedDictionary* aList, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedDictionary_isFull(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			Object* obj = Object_newWith(_this->_testData[i]);
			UnsortedLinkedDictionary_addKeyAndObject(aList,key,obj);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedDictionary_add(AppController* _this, SortedLinkedDictionary* aList, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isFull(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			Object* obj = Object_newWith(_this->_testData[i]);
			SortedLinkedDictionary_addKeyAndObject(aList, key, obj);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd)
{
	char results[255];
	sprintf_s(results, sizeof(results), "크기: %4d, 삽입: %6ld\n", aTestSize, (long)aTimeForAdd);
	AppView_out(results);
}


void AppController_delete(AppController* _this) {
	free(_this->_parameterSet);
	free(_this);
}
