#include "Common.h"

//����Լ�
void AppView_out_msg_startSolvingLinearEquation();
void AppView_out_msg_endSolvingLinearEquation();
void AppView_out_linearEquation(float c0, float c1);
void AppView_out_root(double root);
void AppView_out_msg_firstOrderTermCoefficientlsZero();
void AppView_out_ToSmall_Or_ToLarge();


//�Է��Լ�
Boolean AppView_in_solvingRequested();
void AppView_in_linearEquation(float* p_c0, float* p_c1);
