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

	AppView_out(MSG_TitleForUnsortedArrayDictionary);

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		UnsortedArrayDictionary* listForTest = UnsortedArrayDictionary_new(maxTestSize);
		double timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, listForTest, testSize);
		double timeForSearch = AppController_timeForUnsortedArrayDictionary_search(_this, listForTest, testSize);
		double timeForRemove = AppController_timeForUnsortedArrayDictionary_remove(_this, listForTest, testSize);



		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		UnsortedArrayDictionary_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out("");
	AppView_out(MSG_TitleForSortedArrayDictionary);
	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		SortedArrayDictionary* listForTest = SortedArrayDictionary_new(maxTestSize);
		double timeForAdd = AppController_timeForSortedArrayDictionary_add(_this, listForTest, testSize);
		double timeForSearch = AppController_timeForSortedArrayDictionary_search(_this, listForTest, testSize);
		double timeForRemove = AppController_timeForSortedArrayDictionary_remove(_this, listForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		SortedArrayDictionary_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out("");
	AppView_out(MSG_TitleForUnsortedLinkedDictionary);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		UnsortedLinkedDictionary* listForTest = UnsortedLinkedDictionary_new();
		double timeForAdd = AppController_timeForUnsortedLinkedDictionary_add(_this, listForTest, testSize);
		double timeForSearch = AppController_timeForUnsortedLinkedDictionary_search(_this, listForTest, testSize);
		double timeForRemove = AppController_timeForUnsortedLinkedDictionary_remove(_this, listForTest, testSize);

		

		AppController_showResults(_this, testSize, timeForAdd,timeForSearch, timeForRemove);
		UnsortedLinkedDictionary_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out("");
	AppView_out(MSG_TitleForSortedLinkedDictionary);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		SortedLinkedDictionary* listForTest = SortedLinkedDictionary_new();
		double timeForAdd = AppController_timeForSortedLinkedDictionary_add(_this, listForTest, testSize);
		double timeForSearch = AppController_timeForSortedLinkedDictionary_search(_this, listForTest, testSize);
		double timeForRemove = AppController_timeForSortedLinkedDictionary_remove(_this, listForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		SortedLinkedDictionary_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out("");
	AppView_out(MSG_TitleForBinarySearchTree);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {

		BinarySearchTreeDictionary* listForTest = BinarySearchTreeDictionary_new();
		double timeForAdd = AppController_timeForBinarySearchTree_add(_this, listForTest, testSize);
		double timeForSearch = AppController_timeForBinarySearchTree_search(_this, listForTest, testSize);
		double timeForRemove = AppController_timeForBinarySearchTree_remove(_this, listForTest, testSize);

		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		BinarySearchTreeDictionary_delete(listForTest);
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
			UnsortedLinkedDictionary_addKeyAndObject(aList, key, obj);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedArrayDictionary_add(AppController* _this, UnsortedArrayDictionary* aList, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayDictionary_isFull(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			Object* obj = Object_newWith(_this->_testData[i]);
			UnsortedArrayDictionary_addKeyAndObject(aList, key, obj);
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

double AppController_timeForSortedArrayDictionary_add(AppController* _this, SortedArrayDictionary* aList, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isFull(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			Object* obj = Object_newWith(_this->_testData[i]);
			SortedArrayDictionary_addKeyAndObject(aList, key, obj);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForBinarySearchTree_add(AppController* _this, BinarySearchTreeDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isFull(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			Object* obj = Object_newWith(_this->_testData[i]);
			BinarySearchTreeDictionary_addKeyAndObject(aList, key, obj);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedLinkedDictionary_search(AppController* _this, UnsortedLinkedDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			UnsortedLinkedDictionary_keyDoesExist(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedArrayDictionary_search(AppController* _this, UnsortedArrayDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			UnsortedArrayDictionary_keyDoesExist(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


double AppController_timeForSortedLinkedDictionary_search(AppController* _this, SortedLinkedDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			SortedLinkedDictionary_keyDoesExist(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayDictionary_search(AppController* _this, SortedArrayDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			SortedArrayDictionary_keyDoesExist(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForBinarySearchTree_search(AppController* _this, BinarySearchTreeDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			BinarySearchTreeDictionary_keyDoesExist(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


double AppController_timeForUnsortedLinkedDictionary_remove(AppController* _this, UnsortedLinkedDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			UnsortedLinkedDictionary_removeObjectForKey(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedArrayDictionary_remove(AppController* _this, UnsortedArrayDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			UnsortedArrayDictionary_removeObjectForKey(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


double AppController_timeForSortedLinkedDictionary_remove(AppController* _this, SortedLinkedDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			SortedLinkedDictionary_removeObjectForKey(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayDictionary_remove(AppController* _this, SortedArrayDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			SortedArrayDictionary_removeObjectForKey(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForBinarySearchTree_remove(AppController* _this, BinarySearchTreeDictionary* aList, int aTestSize)
{
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isEmpty(aList)) {
			Key* key = Key_newWith(_this->_testData[i]);
			BinarySearchTreeDictionary_removeObjectForKey(aList, key);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}



// "크기: %4d, 삽입: %6ld, 최솟값 얻기:%7ld, 최대값삭제: %7ld\n",
void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd ,double aTimeForSearch, double aTimeForRemove)
{
	char results[255];
	sprintf_s(results, sizeof(results), "크기: %4d, 삽입: %6ld, 검색:%7ld, 삭제: %7ld" , aTestSize, (long)aTimeForAdd, (long)aTimeForSearch, (long)aTimeForRemove);
	AppView_out(results);
}


void AppController_delete(AppController* _this) {
	ParameterSet_delete(_this->_parameterSet);
	free(_this);
}
