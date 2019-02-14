//  二进制转换十进制 堆栈实现
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"


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
