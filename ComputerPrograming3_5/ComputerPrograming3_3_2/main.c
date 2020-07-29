#include "AppController.h"


int main()
{
	AppController* appController;
	appController = AppController_new();
	AppController_run(appController);
	AppController_delete(appController);

	return 0;
}