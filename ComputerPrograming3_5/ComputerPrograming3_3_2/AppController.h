#include "common.h"

typedef struct _AppController AppController;

AppController* AppController_new();
//��ü�� �����Ѵ�.

void AppController_delete(AppController* _this);
//����� ���� ��ü�� �Ҹ��Ų��.

void AppController_run(AppController* _this);
//�������� main�� ������ �Ѵ�.
//main()���� �� �Լ��� call�Ͽ�, ���� ���۽�Ų��.

