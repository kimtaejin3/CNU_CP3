#include"Common.h"

void AppView_out_msg_startSolvingQuadEquation();

void AppView_out_msg_endSolvingQuadEquation();

Boolean AppView_in_solvingIsRequested();

void AppView_in_quadEquation(float* _c0, float* _c1, float* _c2);

void AppView_out_quadEquation(float c0,float c1,float c2);

void AppView_out_msg_secondOrderTermCoefficientIsZero();

void AppView_out_msg_determinantIsNegative(float determinant);

void AppView_out_solution(double root1, double _root2);

