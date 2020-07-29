#define MAX_STUDENT_ID_LENGTH 9
#include"Common.h"


typedef struct _Student Student;

//주어진 학번과 성적을 갖는다.
Student* Student_new(char* givenStudentID, int givenScore);

void Student_delete(Student* _this);

//학번(문자열)을 얻는다.
char* Student_studentID(Student* _this);

int Student_score(Student* _this);

Boolean Student_studentIDIsValid(char* aStudentID);

Boolean Student_scoreIsValid(int aScore);
