#include"AppController.h"
#define Esc 27
#include<stdlib.h>

struct _AppController {
	Dictionary* _dictionary;
	Traverse* _traverse;
};

AppController* AppController_new() {
	AppController* _this = NewObject(AppController);
	_this->_dictionary = Dictionary_new();
	_this->_traverse = Traverse_new();
	return _this;
}

void AppController_delete(AppController* _this) {
	Traverse_delete(_this->_traverse);
	free(_this);
}

void AppController_run(AppController* _this) {
	AppView_out_startProgram();
	

	char inputChar = AppView_in_charDirectlyFromKeyboard();

	while (inputChar != Esc) {
		if (isAlpha(inputChar)) {
			AppController_add(_this, inputChar);
		}
		else if (inputChar == '?') {
			AppController_search(_this);
		}
		else if (inputChar == '-') {
			AppController_remove(_this);
		}
		else if (inputChar == '#') {
			AppController_showSize(_this);
		}
		else if (inputChar == '/') {
			AppController_showAll(_this);
		}
		else {
			// 의미 없는 문자임을 출력하고 무시.
			AppView_out_ignoredChar();
		}
		AppView_out_newLine();
		inputChar = AppView_in_charDirectlyFromKeyboard();
	}
	AppController_esc(_this);
	AppView_out_endProgram();

}

void AppController_add(AppController* _this, char aChar) {

	if (Dictionary_isFull(_this->_dictionary)) {
		AppView_out_DictionaryIsFull(aChar);
	}
	else
	{
		int IntegerInput = (int)aChar;
		Key* key = Key_newWith(aChar);
		Object* object = Object_newWith(IntegerInput);

		if (!Dictionary_addKeyAndObject(_this->_dictionary, key, object)) {
			Dictionary_replaceObjectForKey(_this->_dictionary, key, object);
			AppView_out_replace(Key_value(key), Object_value(object));	
		}
		else
		{
			//add 성공메세지
			AppView_out_add(Key_value(key), Object_value(object));
		}
	}
	
}

void AppController_search(AppController* _this)
{
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppView_out_noElementInDictionary();
	}
	else {
		char input = AppView_int_char_ForSearch();
		int IntegerInput = (int)input;
		Key* key = Key_newWith(input);
		Object* object = Object_newWith(IntegerInput);

		if (Dictionary_keyDoesExist(_this->_dictionary, key)) {
			AppView_out_search(Key_value(key), Object_value(object));
		}
		else
		{
			AppView_out_EmptyForSearch();
		}
	}
}

void AppController_remove(AppController* _this) {
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppView_out_noElementInDictionary();
	}
	else
	{
		char input = AppView_remove_in();
		int IntegerInput = (int)input;
		Key* key = Key_newWith(input);
		Object* object = Object_newWith(IntegerInput);

		if (Dictionary_removeObjectForKey(_this->_dictionary,key)!=NULL) {
			AppView_out_remove(Key_value(key), Object_value(object));
		}
		else
		{
			AppView_out_EmptyForRemove();
		}

	}
}


void AppController_showSize(AppController* _this)
{
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppView_out_noElementInDictionary();
	}
	else {

	int n=Dictionary_size(_this->_dictionary);
	//메세지
	AppView_out_dictionarySize(n);
	}
}


void AppController_esc(AppController* _this)
{
	Dictionary_delete(_this->_dictionary);
}


void AppController_showAll(AppController* _this) {
	Dictionary_scanInSortedOrder(_this->_dictionary, _this->_traverse);
}
