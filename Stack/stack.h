#ifndef __STACK_DEFINED__
#define __STACK_DEFINED__
#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElementType;


typedef struct stack
{
    ElementType * base;
    ElementType * top;
    int stackSize;
} Stack,*PStack;


PStack initStack(void);
Status Push(PStack s, ElementType data);
Status Pop(PStack s, ElementType* data);
int StackLen(PStack s);
Status ClearStack(PStack s);
Status DeleteStack(PStack s);



#endif