#include"Queue.h"
#include"AppView.h"

typedef struct _AppController AppController;

/*공개함수*/
AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);


/*비공개 함수*/
void AppController_add(AppController* _this, char aChar);
void AppController_removeN(AppController* _this, char aDigit);
void AppController_remove1(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_showAllFromFront(AppController* _this);
void AppController_showFront(AppController* _this);
void AppController_ignore(AppController* _this);
void AppController_esc(AppController* _this);

void AppController_initCharCounts(AppController* _this);
void AppController_countInput(AppController* _this);
void AppController_countIgnored(AppController* _this);
void AppController_countAdded(AppController* _this);
int AppController_numberOfInputChars(AppController* _this);
int AppController_numberOfIgnoredChars(AppController* _this);
int AppController_numberOfNormallyProcessedChars(AppController* _this);
int AppController_numberOfPushedChars(AppController* _this);
void AppController_showStatistics(AppController* _this);
