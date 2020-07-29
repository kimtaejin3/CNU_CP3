#define MAX_STUDENT_ID_LENGTH 9
#include"Common.h"


typedef struct _Student Student;

//�־��� �й��� ������ ���´�.
Student* Student_new(char* givenStudentID, int givenScore);

void Student_delete(Student* _this);

//�й�(���ڿ�)�� ��´�.
char* Student_studentID(Student* _this);

int Student_score(Student* _this);

Boolean Student_studentIDIsValid(char* aStudentID);

Boolean Student_scoreIsValid(int aScore);
