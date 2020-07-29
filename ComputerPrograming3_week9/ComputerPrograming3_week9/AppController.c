#include"AppController.h"
#include<stdlib.h>//pop을 통해 얻은 원소를 할당해제하기 위함.
#define Esc 27
#include<stdio.h>
struct _AppController {
	Stack* _stack;
	int _inputChars;
	int _ignoredChars;
	int _pushedChars;
};

/*공개함수*/
AppController* AppController_new() {
	AppController* _this;
	_this = NewObject(AppController);
	_this->_stack = Stack_new();
	return _this;
}

void AppController_delete(AppController* _this)
{
	Stack_delete(_this->_stack);
	free(_this);
}


/*생성자*/
void AppController_run(AppController* _this)
{
	AppView_out_startProgram();

	AppController_initCountingChars(_this);
	char c = AppView_in_charDirectlyFromKeyboard();
	while (c != Esc) {
		AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_push(_this, c);
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_pops(_this, digitValue);
		}
		else if (c == '-') {
			AppController_pop1(_this);
		}
		else if (c == '#') {
			AppController_showSize(_this);
		}
		else if (c == '/') {
			AppController_showAllFromBottom(_this);
		}
		else if (c == '\\') {
			AppController_showAllFromTop(_this);
		}
		else if (c == '^') {
			AppController_showTopElement(_this);
		}
		else {
			AppController_ignore(_this);
		}
		AppView_out_newLine();
		c = AppView_in_charDirectlyFromKeyboard();
	}
	AppController_endInput(_this);
	AppController_showStatistics(_this);
	AppView_out_endProgram();
}

/*AppController의 비공개 함수*/

void AppController_push(AppController* _this, char aChar)
{
	if (Stack_isFull(_this->_stack)) {
		AppView_out_stackIsFullAgainstPush(aChar);
	}
	else {
		Stack_push(_this->_stack, aChar);
		AppController_countPushedChars(_this);
		AppView_out_pushedElement(aChar);
	}
}

void AppController_pops(AppController* _this, int numberOfChars)
{
	AppView_out_beginPops(numberOfChars);
	for (int i = 0; i < numberOfChars; i++) {
		if (Stack_isEmpty(_this->_stack)) {
			AppView_out_stackIsEmptyAgainstPops();
			return;
		}
		char* poppedChar = Stack_pop(_this->_stack);//NULL을 받을 수 있어야 함.
		AppView_out_poppedElementByPop1(*poppedChar);
		free(poppedChar);
	}
	AppView_out_endPops();
}

void AppController_pop1(AppController* _this)
{
	if (Stack_isEmpty(_this->_stack)) {
		AppView_out_stackIsEmptyAgainstPop1();
	}
	else {
		char *poppedChar = Stack_pop(_this->_stack);
		AppView_out_poppedElementByPop1(*poppedChar);
		free(poppedChar);//pop()을 수행하여 얻은 포인터형 변수를 할당해제
	}
}

void AppController_showSize(AppController* _this)
{
	int stackSize = Stack_size(_this->_stack);
	AppView_out_stackSize(stackSize);
	AppView_out_newLine();
}

void AppController_showAllFromBottom(AppController* _this)
{
	char stackElement;
	AppView_out_bottomOfStack();
	for (int i = 0; i < Stack_size(_this->_stack); i++) {
		stackElement = Stack_elementAt(_this->_stack, i);
		AppView_out_element(stackElement);
	}
	AppView_out_topOfStack();
	AppView_out_newLine();
}

void AppController_showAllFromTop(AppController* _this) {
	char stackElement;
	AppView_out_topOfStack();
	for (int i = Stack_size(_this->_stack)-1; i >=0; i--) {
		stackElement = Stack_elementAt(_this->_stack, i);
		AppView_out_element(stackElement);
	}
	AppView_out_bottomOfStack();
	AppView_out_newLine();
}

void AppController_showTopElement(AppController* _this) {
	if (Stack_isEmpty(_this->_stack)) {
		AppView_out_noTopElement();
	}
	else {
		char topElement = Stack_topElement(_this->_stack);
		AppView_out_topElement(topElement);
	}
}

void AppController_ignore(AppController* _this) {
	AppView_out_ignoredChar();
	AppController_countIgnoredChars(_this);
}

void AppController_endInput(AppController* _this) {
	
	AppView_out_endInput();
	int FirstStackSize = Stack_size(_this->_stack);
	for (int i = 0; i < FirstStackSize; i++) {
		if (Stack_isEmpty(_this->_stack)) {
			AppView_out_stackIsEmptyAgainstPops();
			return;
		}
		char* poppedChar = Stack_pop(_this->_stack);//NULL을 받을 수 있어야 함.
		AppView_out_poppedElementByEndInput(*poppedChar);
		free(poppedChar);//pop()을 수행하여 얻은 포인터형 변수를 할당해제
	}
}

void AppController_initCountingChars(AppController* _this) {
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_pushedChars = 0;
}

void AppController_countInputChars(AppController* _this) {
	_this->_inputChars++;
}
void AppController_countIgnoredChars(AppController* _this) {
	_this->_ignoredChars++;
}
void AppController_countPushedChars(AppController* _this) {
	_this->_pushedChars++;
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
int AppController_numberOfPushedChars(AppController* _this) {
	return (_this->_pushedChars);
}

void AppController_showStatistics(AppController* _this)
{
	AppView_out_newLine();
	AppView_out_numberOfInputChars(AppController_numberOfInputChars(_this));
	AppView_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppView_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppView_out_numberOfPushedChars(AppController_numberOfPushedChars(_this));
}
