#include"AppView.h"
#include"Dictionary.h"
#include"Traverse.h"

typedef struct _AppController AppController;

/*공개함수*/
AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);


/*비공개 함수*/
void AppController_add(AppController* _this, char aChar);
void AppController_remove(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_showAll(AppController* _this);
void AppController_search(AppController* _this);


void AppController_esc(AppController* _this);




