#include"Common.h"
#include"Infix.h"
#include"Postfix.h"


typedef struct _AppController AppController;

AppController* AppController_New();

void AppController_run(AppController* _this);

void AppController_delete(AppController* _this);

