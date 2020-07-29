#ifndef COMMON_H
#define COMMON_H

#define ELEMENT_DOES_NOT_EXIST -1
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum { FALSE, TRUE } Boolean;


#endif 
