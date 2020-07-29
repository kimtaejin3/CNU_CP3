#include "Common.h"
#include<windows.h>

typedef struct {
	LARGE_INTEGER _frequency;
	LARGE_INTEGER _startCounter;
	LARGE_INTEGER _stopCounter;
}Timer;

Timer* Timer_new();

void Timer_delete(Timer* _this);
void Timer_start(Timer* _this);
void Timer_stop(Timer* _this);
double Timer_duration(Timer* _this);

