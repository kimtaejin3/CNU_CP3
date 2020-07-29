#include"AppView.h"


// 키보드에서 키를 치면 그 키의 문자 값을 바로 얻게 됨
// Microsoft C 의 _getch()는 표준 C 함수가 아님 (<conio.h>에 있음)
char getCharDirectlyFromKeyboard(void)
{
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

char AppView_in_charDirectlyFromKeyboard(void)
{
	printf("문자를 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppView_int_char_ForSearch(void)
{
	printf("검색할 객체의 Key값을 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppView_in_char_ForRemove(void)
{
	printf("삭제할 객체의 Key값을 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

void AppView_out_DictionaryIsFull(char anElementForPush)
{
	printf("[Add: Full] 딕셔너리가 꽉 차서 키 \'%c\' 는 삽입이 불가능합니다.\n", anElementForPush);

}

void AppView_out_add(KeyValue aKey, ObjectValue anObject)
{
	printf("[Add] 삽입된 키-객체 쌍은 <\'%c\',%d> 입니다.\n ", aKey, anObject);

}

void AppView_out_replace(KeyValue aKey, ObjectValue anObject)
{
	printf("\"[Replace] Key <\'%c\'>의 object를 <%d>로 대체합니다.\" \n ", aKey, anObject);
}


void AppView_out_noElementInDictionary()
{
	printf("[Empty] 딕셔너리에 원소가 없습니다.\n");

}
void AppView_out_remove(KeyValue aKey, ObjectValue anObject)
{
	printf("\"[Remove] Key <\'%c\',%d>이 성공적으로 삭제되었습니다.\" \n ", aKey, anObject);
}

char AppView_remove_in()
{
	printf("삭제할 객체의 Key 값을 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

void AppView_out_newLine()
{
	printf("\n");
}
void AppView_out_dictionarySize(int Size)
{
	printf("[Size] 딕셔너리에는 현재 %d 개의 Key-Object쌍이 있습니다.\n", Size);

}
void AppView_out_ignoredChar()
{
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");

}

void AppView_out_search(KeyValue aKey, ObjectValue anObject)
{
	printf("\"[Search]  <\'%c\',%d> 쌍이 사전에 존재합니다.\" \n ", aKey, anObject);
}

void AppView_out_EmptyForSearch()
{
	printf("\"[Search] 주어진 키가 사전에 존재하지 않습니다.\" \n ");

}

void AppView_out_EmptyForRemove()
{
	printf("\"[Remove] 주어진 키가 사전에 존재하지 않습니다.\" \n");

}

void AppView_out(char* aString)
{
	printf("%s", aString);
}

void AppView_out_startProgram()
{
	printf("<<< 사전 활용 프로그램을 시작합니다 >>>\n ");
	AppView_out_newLine();
}

void AppView_out_endProgram()
{
	AppView_out_newLine();
	printf("<<< 사전 활용 프로그램을 종료합니다 >>>\n ");
}
