#include"AppController.h"

int main(void) {

	AppController* appController = AppController_New();
	AppController_run(appController);
	AppController_delete(appController);
	return 0;
}
