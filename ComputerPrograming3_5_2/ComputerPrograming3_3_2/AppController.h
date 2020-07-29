#include "common.h"

typedef struct _AppController AppController;

AppController* AppController_new();
//객체를 생성한다.

void AppController_delete(AppController* _this);
//사용이 끝난 객체는 소멸시킨다.

void AppController_run(AppController* _this);
//실질적인 main의 역할을 한다.
//main()에서 이 함수를 call하여, 앱을 제작시킨다.

