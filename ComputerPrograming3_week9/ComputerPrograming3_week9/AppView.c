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

void AppView_out_stackIsFullAgainstPush(char anElementForPush)
{
	printf("[Push: Full] ������ �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForPush);
}
 void AppView_out_pushedElement(char anElement)
{
	 printf("[Push] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n ", anElement);
 }

void AppView_out_stackIsEmptyAgainstPop1()
{
	printf("[Pop1: Empty] ���ÿ� ������ ���Ұ� �����ϴ�.\n");
}
void AppView_out_poppedElementByPop1(char anElement)
{
	printf("[Pop1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppView_out_beginPops(int numberOfElements)
{
	printf("[Pops] %d ���� ���Ҹ� �����Ϸ��� �մϴ�:\n", numberOfElements);
}
void AppView_out_endPops()
{
	printf("[Pops] ������ �����մϴ�. \n");
}
void AppView_out_stackIsEmptyAgainstPops()
{
	printf("[Pops: Empty] ���ÿ� �� �̻� ������ ���Ұ� �����ϴ�.\n");
}
void AppView_out_topElement(char anElement)
{
	printf("[Top] Top ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppView_out_noTopElement()
{
	printf("[Top: Empty] ���� ������ ��� �ֽ��ϴ�.\n");
}

void AppView_out_bottomOfStack()
{
	printf("<Bottom of Stack> ");
}
void AppView_out_element(char anElement)
{
	printf("%c ", anElement);
}
void AppView_out_topOfStack()
{
	printf("<Top of Stack> ");
}
void AppView_out_newLine()
{
	printf("\n");
}
void AppView_out_stackSize(int stackSize)
{
	printf("[Size] ���ÿ��� ���� %d ���� ���Ұ� �ֽ��ϴ�.\n", stackSize);
}
void AppView_out_ignoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}
void AppView_out_endInput()
{
	printf("[End Input] �Է��� �����ϸ�, ������ ��� ���Ҹ� �����մϴ�:\n");
}
void AppView_out_poppedElementByEndInput(char anElement)
{
	printf("-End Input: ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_out_numberOfInputChars(int numberOfChars)
{
	printf("�����Էµ� ���ڴ� ��� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_out_numberOfNormallyProcessedChars(int numberOfChars)
{
	printf("������������ ó���� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_out_numberOfIgnoredChars(int numberOfChars)
{
	printf("�������õ� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_out_numberOfPushedChars(int numberOfChars)
{
	printf("�������ÿ� ���� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppView_out_startProgram()
{
	printf("<<< ���� ó�� ���α׷��� �����մϴ� >>>\n ");
	AppView_out_newLine();
}
void AppView_out_endProgram()
{
	AppView_out_newLine();
	printf("<<< ���� ó�� ���α׷��� �����մϴ� >>>\n ");
}
