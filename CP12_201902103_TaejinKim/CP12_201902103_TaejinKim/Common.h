#ifndef Common_h
#define Common_h

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define isDigit(CHAR) (('0'<=CHAR)&&(CHAR<='9'))

typedef enum { FALSE, TRUE } Boolean;
typedef enum {
	PostfixError_None,
	PostfixError_ExpressionTooLong,
	PostfixError_OperandsTooMany,
	PostfixError_OperandsTooFew,
	PostfixError_UnknownOperator,
	PostfixError_DivideByZero
}PostfixError;

#endif // !Conmmon_h

