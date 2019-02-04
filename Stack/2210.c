//  二进制转换十进制 堆栈实现

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main(int argc, char const *argv[])
{
    PStack s = initStack();
    ElementType ch;
    int sum = 0;
    int count = 0;
    printf("请输入二进制数据:");
    scanf("%c",&ch);
    while(ch != '\n'){
        if (Push(s, ch)) {
           printf("数据%c入栈成功\n",ch);
        }
        scanf("%c",&ch);
    }
    printf("堆栈已用空间为:%d\n全部空间大小为:%d\n",s->top-s->base,s->stackSize);

    count = s->top-s->base;
    for(int i = 0; i < count; i++)
    {   Pop(s,&ch);
        sum += (ch-48)*pow(2,i);
    }
    printf("转换的结果为:%d\n", sum);

    return 0;
}


// 初始化堆栈，返回堆栈结构体指针
PStack initStack(void){
    PStack s = (PStack)malloc(sizeof(Stack));
    s->base = (ElementType *)malloc(sizeof(ElementType) * STACK_MAX_SIZE);
    if (s->base == NULL) {
        printf("栈底为NULL, 初始化栈失败\n");
        exit(-1);
    }

    s->top = s->base;
    s->stackSize = STACK_MAX_SIZE;
    return s;
}


Status Push(PStack s, ElementType data){
    if (s->top - s->base == s->stackSize) {
        printf("堆栈已满,数据入栈失败\n");
        return ERROR;
    }
    *(s->top) = data;
    s->top++;
    return OK;
}

Status Pop(PStack s, ElementType* data){
    if (s->top == s->base) {
        printf("堆栈已空,数据出栈失败\n");
        return ERROR;
    }

    s->top--;
    *data = *(s->top);

    return OK;
}


//返回堆栈的长度
int StackLen(PStack s){
    return s->top-s->base;
}

//清空堆栈
Status ClearStack(PStack s){
    s->top = s->base;
    return OK;
}

//删除堆栈
Status DeleteStack(PStack s){

    if (s->base == NULL) {
        printf("栈底为NULL, 堆栈删除失败\n");
        return ERROR;    
    }

    int lenth = s->stackSize;
    
    for(int i = 0; i < lenth; i++)
    {
        free(s->base);
        s->base++;
    }
    s->stackSize = 0;
    s->base = s->top = NULL;
    return OK;
}
