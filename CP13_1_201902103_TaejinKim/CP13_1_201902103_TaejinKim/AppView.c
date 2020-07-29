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

void AppView_out_queueIsFull(char anElementForPush)
{
	printf("[Add: Full] ť�� �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForPush);

}

void AppView_out_addedElementInQueue(char anElement)
{
	printf("[Add] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n ", anElement);

}

void AppView_out_noElementInQueue()
{
	printf("[Empty] ť�� ������ ���Ұ� �����ϴ�.\n");

}
void AppView_out_removedElementFromQueue(char anElement)
{
	printf("[Remove1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppView_out_removedNElementFromQueue(char anElement)
{
	printf("[RemoveN] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppView_out_removedNElementFromQueueEnd(char anElement)
{
	printf("[END] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppView_out_queueIsEmptyAgainstRemoveN()
{
	printf("[Empty] ť�� �� �̻� ������ ���Ұ� �����ϴ�.\n");

}

void AppView_out_queueIsEmptyAgainstRemoveNAtEnd()
{
	printf("[End] ť�� �� �̻� ������ ���Ұ� �����ϴ�.\n");

}

void AppView_out_frontElement(char anElement)
{
	printf("[Front] Front ���Ҵ� \'%c\' �Դϴ�.\n", anElement);

}
void AppView_out_noFrontElement()
{
	printf("[Empty] ���� ť�� ��� �ֽ��ϴ�.\n");

}

void AppView_out_labelFront()
{
	printf("[Queue] <Front> ");
}
void AppView_out_elementInQueue(char anElement)
{
	printf("%c ", anElement);
}
void AppView_out_labelRear()
{
	printf("<Rear> \n");

}
void AppView_out_newLine()
{
	printf("\n");
}
void AppView_out_queueSize(int queueSize)
{
	printf("[Size] ť���� ���� %d ���� ���Ұ� �ֽ��ϴ�.\n", queueSize);

}
void AppView_out_ignoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");

}

void AppView_out_poppedElementByEndInput(char anElement)
{
	printf("[Esc] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);

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
	printf("<<< Queue Ȱ�� ���α׷��� �����մϴ� >>>\n ");
	AppView_out_newLine();
}
void AppView_out_endProgram()
{
	AppView_out_newLine();
	printf("<<< Queue Ȱ�� ���α׷��� �����մϴ� >>>\n ");
}
