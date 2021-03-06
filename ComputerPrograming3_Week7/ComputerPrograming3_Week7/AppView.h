//출력을 위한 공개함수

void AppView_out(char* s);
void AppView_out_averageScore(float anAverageScore);
void AppView_out_numberOfStudentsAboveAverage(int aNumber);
void AppView_out_maxScore(int aMaxScore);
void AppView_out_minScore(int aMinScore);
void AppView_out_gradeCountFor(char aGrade, int aCount);
void AppView_out_studentInfo(char* studentID,int aScore, char grade);
void AppView_out_msg_invalidStudentID(char *aStudentID, int maxLength);
void AppView_out_msg_invalidScore(aScore);


// 입력을 위한 공개함수
Boolean AppView_in_doesContinueToInputNextStudent();
int AppView_in_score();
void AppView_in_studentID(char* aStudentID);
