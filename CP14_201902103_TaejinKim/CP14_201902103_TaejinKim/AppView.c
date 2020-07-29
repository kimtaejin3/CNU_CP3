#include"AppView.h"


// Ű���忡�� Ű�� ġ�� �� Ű�� ���� ���� �ٷ� ��� ��
// Microsoft C �� _getch()�� ǥ�� C �Լ��� �ƴ� (<conio.h>�� ����)
char getCharDirectlyFromKeyboard(void)
{
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

char AppView_in_charDirectlyFromKeyboard(void)
{
	printf("���ڸ� �Է��Ͻÿ�: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppView_int_char_ForSearch(void)
{
	printf("�˻��� ��ü�� Key���� �Է��Ͻÿ�: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

char AppView_in_char_ForRemove(void)
{
	printf("������ ��ü�� Key���� �Է��Ͻÿ�: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();
	return charDirectlyFromKeyboard;
}

void AppView_out_DictionaryIsFull(char anElementForPush)
{
	printf("[Add: Full] ��ųʸ��� �� ���� Ű \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForPush);

}

void AppView_out_add(KeyValue aKey, ObjectValue anObject)
{
	printf("[Add] ���Ե� Ű-��ü ���� <\'%c\',%d> �Դϴ�.\n ", aKey, anObject);

}

void AppView_out_replace(KeyValue aKey, ObjectValue anObject)
{
	printf("\"[Replace] Key <\'%c\'>�� object�� <%d>�� ��ü�մϴ�.\" \n ", aKey, anObject);
}


void AppView_out_noElementInDictionary()
{
	printf("[Empty] ��ųʸ��� ���Ұ� �����ϴ�.\n");

}
void AppView_out_remove(KeyValue aKey, ObjectValue anObject)
{
	printf("\"[Remove] Key <\'%c\',%d>�� ���������� �����Ǿ����ϴ�.\" \n ", aKey, anObject);
}

char AppView_remove_in()
{
	printf("������ ��ü�� Key ���� �Է��Ͻÿ�: ");
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
	printf("[Size] ��ųʸ����� ���� %d ���� Key-Object���� �ֽ��ϴ�.\n", Size);

}
void AppView_out_ignoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");

}

void AppView_out_search(KeyValue aKey, ObjectValue anObject)
{
	printf("\"[Search]  <\'%c\',%d> ���� ������ �����մϴ�.\" \n ", aKey, anObject);
}

void AppView_out_EmptyForSearch()
{
	printf("\"[Search] �־��� Ű�� ������ �������� �ʽ��ϴ�.\" \n ");

}

void AppView_out_EmptyForRemove()
{
	printf("\"[Remove] �־��� Ű�� ������ �������� �ʽ��ϴ�.\" \n");

}

void AppView_out(char* aString)
{
	printf("%s", aString);
}

void AppView_out_startProgram()
{
	printf("<<< ���� Ȱ�� ���α׷��� �����մϴ� >>>\n ");
	AppView_out_newLine();
}

void AppView_out_endProgram()
{
	AppView_out_newLine();
	printf("<<< ���� Ȱ�� ���α׷��� �����մϴ� >>>\n ");
}
