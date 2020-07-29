#include<stdio.h>
#include <conio.h>
#include"Key.h"
#include"Object.h"


char getCharDirectlyFromKeyboard(void);


char AppView_in_charDirectlyFromKeyboard(void);


char AppView_int_char_ForSearch(void);


char AppView_in_char_ForRemove(void);

void AppView_out_DictionaryIsFull(char anElementForPush);


void AppView_out_add(KeyValue aKey, ObjectValue anObject);


void AppView_out_replace(KeyValue aKey, ObjectValue anObject);


void AppView_out_noElementInDictionary();
void AppView_out_remove(KeyValue aKey, ObjectValue anObject);


char AppView_remove_in();


void AppView_out_newLine();

void AppView_out_dictionarySize(int Size);
void AppView_out_ignoredChar();


void AppView_out_search(KeyValue aKey, ObjectValue anObject);

void AppView_out_EmptyForSearch();

void AppView_out_EmptyForRemove();


void AppView_out(char* aString);

void AppView_out_startProgram();


void AppView_out_endProgram();



