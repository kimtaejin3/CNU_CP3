#ifndef COMMON_H
#define COMMON_H


#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE));
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE);
#define isAlpha(CHAR) (((65<=CHAR)&&(CHAR<=90))||((97<=CHAR)&&(CHAR<=122)))
typedef enum { FALSE, TRUE } Boolean;

#endif // !COMMON_H

