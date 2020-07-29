#ifndef COMMON
#define COMMON

#include<stdlib.h>
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE)(TYPE*)malloc(sizeof(TYPE)*SIZE)
#define SWAP(TYPE,A,B) {TYPE t=A; A=B; B=t;}

typedef enum{FALSE, TRUE} Boolean;


#endif 
