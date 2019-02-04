//  逆波兰计算器

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define STR_DOUBLE_MAX 10

typedef int Status;
typedef double ElementType;


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
    char ch;
    char str[STR_DOUBLE_MAX];
    int i=0;
    double e;
    double f;
    double result;
    printf("#####################逆波兰计算器#####################\n");
    printf("请输入表达式(回车结束输入):");
    scanf("%c", &ch);
    while(ch!='\n'){

        while(isdigit(ch) ||ch=='.' ){
            str[i++] = ch;
            str[i] = '\0';
            if (i==STR_DOUBLE_MAX) {
                printf("超过小数转换范围\n");
                return -1;
            }
            
            scanf("%c", &ch);
            if (ch == ' ') {
                Push(s, atof(str));
                i = 0;
                break;
            }
           

        }
        
        switch (ch)
        {
            case '+':
                Pop(s, &e);
                Pop(s, &f);
                Push(s, e+f);
                break;
            case '-':
                Pop(s, &e);
                Pop(s, &f);
                Push(s, f-e);
                break;
            case '*':
                Pop(s, &e);
                Pop(s, &f);
                Push(s, f*e);
                break;
            case '/':
                Pop(s, &e);
                Pop(s, &f);
                if (!e) {
                    printf("除数为0, 错误\n");
                    return -1;
                }
                Push(s, f/e);
                break;
        }
        scanf("%c",&ch);
    }

    if (Pop(s, &result)) {
        printf("输出的结果是:%f\n", result);
    }

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
