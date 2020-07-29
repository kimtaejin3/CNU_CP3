#include"AppController.h"
#define Esc 27
#define DEFAULT_QUEUE_SIZE 4
#include<stdlib.h>


struct _AppController {
	Queue* _queue;
	int _inputChars;
	int _ignoredChars;
	int _addedChars;
};

AppController* AppController_new() {
	AppController* _this = NewObject(AppController);
	_this->_queue = Queue_new(DEFAULT_QUEUE_SIZE);
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
	return _this;
}

void AppController_delete(AppController* _this) {
	Queue_delete(_this->_queue);
	free(_this);
}

void AppController_run(AppController* _this) {
	AppView_out_startProgram();
	AppController_initCharCounts(_this);

	char inputChar = AppView_in_charDirectlyFromKeyboard();

	while (inputChar != Esc) {
		if (isAlpha(inputChar)) {
			AppController_add(_this, inputChar);
		}
		else if (isDigit(inputChar)) {
			AppController_removeN(_this, inputChar);
		}
		else if (inputChar == '-') {
			AppController_remove1(_this);
		}
		else if (inputChar == '#') {
			AppController_showSize(_this);
		}
		else if (inputChar == '/') {
			AppController_showAllFromFront(_this);
		}
		else if (inputChar == '^') {
			AppController_showFront(_this);
		}
		else {
			AppController_ignore(_this);
		}
		AppView_out_newLine();
		inputChar = AppView_in_charDirectlyFromKeyboard();
		AppController_countInput(_this);
	}
	AppController_esc(_this);
	AppController_showStatistics(_this);
	AppView_out_endProgram();

}

void AppController_add(AppController* _this, char aChar) {

	if (Queue_isFull(_this->_queue)) {
		AppView_out_queueIsFull(aChar);//Å¥°¡ ²ËÂ÷¼­ »ðÀÔ ºÒ°¡
	}
	else {
		Queue_add(_this->_queue, aChar);
		AppController_countAdded(_this);
		AppView_out_addedElementInQueue(aChar);//»ðÀÔ ¼º°ø¸Þ¼¼Áö
	}
}

void AppController_remove1(AppController* _this) {
	char removedChar;
	if (Queue_isEmpty(_this->_queue)) {
		AppView_out_noElementInQueue();
	}
	else {
		removedChar = Queue_remove(_this->_queue);
		AppView_out_removedElementFromQueue(removedChar);
	}
}

void AppController_removeN(AppController* _this, char aDigit)
{
	int numberOfCharsRemoved = aDigit - '0';
	char removedChar;
	if (Queue_isEmpty(_this->_queue)) {
		AppView_out_noElementInQueue();
	}
	else {
		for (int i = 0; i < numberOfCharsRemoved; i++) {
			if (Queue_isEmpty(_this->_queue)) {
				AppView_out_queueIsEmptyAgainstRemoveN();
			}
			else {
				removedChar = Queue_remove(_this->_queue);
				AppView_out_removedNElementFromQueue(removedChar);
			}
		}
	}
}

void AppController_showSize(AppController* _this)
{
	int queueSize = Queue_size(_this->_queue);
	AppView_out_queueSize(queueSize);
	AppView_out_newLine();
}

void AppController_showFront(AppController* _this)
{
	if (Queue_isEmpty(_this->_queue)) {
		AppView_out_noFrontElement();
	}
	else
	{
		char FrontElement = Queue_Front(_this->_queue);
		AppView_out_frontElement(FrontElement);
	}
}

void AppController_ignore(AppController* _this)
{
	AppView_out_ignoredChar();
	AppController_countIgnored(_this);
}

void AppController_esc(AppController* _this)
{
	int QueueSize = Queue_size(_this->_queue);
	for (int i = 0; i < QueueSize; i++) {
		if (Queue_isEmpty(_this->_queue)) {
			AppView_out_queueIsEmptyAgainstRemoveNAtEnd();
			return;
		}
		char removeChar = Queue_remove(_this->_queue);
		AppView_out_poppedElementByEndInput(removeChar);
	}
}


void AppController_initCharCounts(AppController* _this)
{
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
}

void AppController_countInput(AppController* _this) {
	_this->_inputChars++;
}


void AppController_countIgnored(AppController* _this)
{
	_this->_ignoredChars++;
}

void AppController_countAdded(AppController* _this) {
	_this->_addedChars++;
}

void AppController_showAllFromFront(AppController* _this) {
	AppView_out_labelFront();
	for (int i = 0; i < Queue_size(_this->_queue); i++) {
		AppView_out_elementInQueue(Queue_elementAt(_this->_queue, i));
	}
	AppView_out_labelRear();
}

int AppController_numberOfInputChars(AppController* _this) {
	return (_this->_inputChars);
}
int AppController_numberOfIgnoredChars(AppController* _this) {
	return (_this->_ignoredChars);

}
int AppController_numberOfNormallyProcessedChars(AppController* _this) {
	return (_this->_inputChars - _this->_ignoredChars);
}
int AppController_numberOfPushedChars(AppController * _this) {
	return (_this->_addedChars);
}

void AppController_showStatistics(AppController * _this)
{
	AppView_out_newLine();
	AppView_out_numberOfInputChars(AppController_numberOfInputChars(_this));
	AppView_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppView_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppView_out_numberOfPushedChars(AppController_numberOfPushedChars(_this));
}