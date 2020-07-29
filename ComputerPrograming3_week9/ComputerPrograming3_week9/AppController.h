#include"Stack.h"
#include"AppView.h"

typedef struct _AppController AppController;

/*공개함수*/
AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);


/*비공개 함수*/
void AppController_push(AppController* _this, char aChar);
void AppController_pops(AppController* _this, int numberOfChars);
void AppController_pop1(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_showAllFromBottom(AppController* _this);
void AppController_showAllFromTop(AppController* _this);
void AppController_showTopElement(AppController* _this);
void AppController_ignore(AppController* _this);
void AppController_endInput(AppController* _this);

void AppController_initCountingChars(AppController* _this);
void AppController_countInputChars(AppController* _this);
void AppController_countIgnoredChars(AppController* _this);
void AppController_countPushedChars(AppController* _this);
int AppController_numberOfInputChars(AppController* _this);
int AppController_numberOfIgnoredChars(AppController* _this);
int AppController_numberOfNormallyProcessedChars(AppController* _this);
int AppController_numberOfPushedChars(AppController* _this);
void AppController_showStatistics(AppController* _this);
