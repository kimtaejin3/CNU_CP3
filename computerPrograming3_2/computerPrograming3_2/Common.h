#ifndef __Commn_h__
#define __Commn_h__

#include<math.h>
#define MAXFLOAT 1.0E+100
#define EPSILON 1.0E-6
#define FloatValueIsZero(NUMBER) (fabsf(NUMBER)<EPSILON)
#define DoubleValueIsZero(NUMBER) (fabsl(NUMBER)<EPSILON)

typedef enum { FALSE, TRUE } Boolean;

typedef struct {
	double _root1;
	double _root2;
}Solution;

typedef struct {
	float _c0;
	float _c1;
	float _c2;
}QuadEquation;

#endif 
