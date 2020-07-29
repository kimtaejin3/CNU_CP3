#ifndef Common_h
#define Common_h

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum{FALSE, TRUE} Boolean;


#endif // !Conmmon_h
