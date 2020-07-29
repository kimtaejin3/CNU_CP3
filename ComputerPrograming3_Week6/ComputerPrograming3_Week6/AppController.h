#include"Ban.h"

typedef struct {
	Ban* _ban;
}AppController;


AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);