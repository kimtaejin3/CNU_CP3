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

void AppView_out_queueIsFull(char anElementForPush)
{
	printf("[Add: Full] 큐가 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n", anElementForPush);

}

void AppView_out_addedElementInQueue(char anElement)
{
	printf("[Add] 삽입된 원소는 \'%c\' 입니다.\n ", anElement);

}

void AppView_out_noElementInQueue()
{
	printf("[Empty] 큐에 삭제할 원소가 없습니다.\n");

}
void AppView_out_removedElementFromQueue(char anElement)
{
	printf("[Remove1] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}
void AppView_out_removedNElementFromQueue(char anElement)
{
	printf("[RemoveN] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}
void AppView_out_removedNElementFromQueueEnd(char anElement)
{
	printf("[END] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}
void AppView_out_queueIsEmptyAgainstRemoveN()
{
	printf("[Empty] 큐에 더 이상 삭제할 원소가 없습니다.\n");

}

void AppView_out_queueIsEmptyAgainstRemoveNAtEnd()
{
	printf("[End] 큐에 더 이상 삭제할 원소가 없습니다.\n");

}

void AppView_out_frontElement(char anElement)
{
	printf("[Front] Front 원소는 \'%c\' 입니다.\n", anElement);

}
void AppView_out_noFrontElement()
{
	printf("[Empty] 현재 큐는 비어 있습니다.\n");

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
	printf("[Size] 큐에는 현재 %d 개의 원소가 있습니다.\n", queueSize);

}
void AppView_out_ignoredChar()
{
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");

}

void AppView_out_poppedElementByEndInput(char anElement)
{
	printf("[Esc] 삭제된 원소는 \'%c\' 입니다.\n", anElement);

}

void AppView_out_numberOfInputChars(int numberOfChars)
{
	printf("……입력된 문자는 모두 %d 개 입니다.\n ", numberOfChars);
}
void AppView_out_numberOfNormallyProcessedChars(int numberOfChars)
{
	printf("……정상으로 처리된 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppView_out_numberOfIgnoredChars(int numberOfChars)
{
	printf("……무시된 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppView_out_numberOfPushedChars(int numberOfChars)
{
	printf("……스택에 넣은 문자는 %d 개 입니다.\n ", numberOfChars);
}
void AppView_out_startProgram()
{
	printf("<<< Queue 활용 프로그램을 시작합니다 >>>\n ");
	AppView_out_newLine();
}
void AppView_out_endProgram()
{
	AppView_out_newLine();
	printf("<<< Queue 활용 프로그램을 종료합니다 >>>\n ");
}
