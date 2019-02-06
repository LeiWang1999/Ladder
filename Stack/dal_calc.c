//  中缀表达式转换成后缀表达式
//  之后再直接用逆波兰计算器计算

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
void dal2rpn(PStack s, PStack stack_rpn);
int main(int argc, char const *argv[])
{
    PStack s = initStack();
    PStack stack_rpn = initStack();
    dal2rpn(s, stack_rpn);
    while(StackLen(stack_rpn)){
        Pop(stack_rpn, s->top);
        s->top++;
    }
    char ch;
    char str[STR_DOUBLE_MAX];
    int i=0;
    double e;
    double f;
    double result;
    Pop(s, &ch);
    typedef double ElementType;
    PStack s3 = initStack();
    while(ch!='\n'){

        while(isdigit(ch) ||ch=='.' ){
            str[i++] = ch;
            str[i] = '\0';
            if (i==STR_DOUBLE_MAX) {
                printf("超过小数转换范围\n");
                return -1;
            }
            
            Pop(s, &ch);
            if (ch == ' ') {
                Push(s3, atof(str));
                i = 0;
                break;
            }
           

        }
        
        switch (ch)
        {
            case '+':
                Pop(s3, &e);
                Pop(s3, &f);
                Push(s3, e+f);
                break;
            case '-':
                Pop(s3, &e);
                Pop(s3, &f);
                Push(s3, f-e);
                break;
            case '*':
                Pop(s3, &e);
                Pop(s3, &f);
                Push(s, f*e);
                break;
            case '/':
                Pop(s3, &e);
                Pop(s3, &f);
                if (!e) {
                    printf("除数为0, 错误\n");
                    return -1;
                }
                Push(s3, f/e);
                break;
        }
            Pop(s3, &ch);
    }

    if (Pop(s3, &result)) {
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


/*dal2rpn
转换过程需要用到栈，具体过程如下：
1）如果遇到操作数，我们就直接将其输出。
2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。*/
void dal2rpn(PStack s, PStack stack_rpn){

    char ch;
    ElementType e;
    printf("请输入紧凑的中缀表达式:");
    scanf("%c", &ch);
    while(TRUE){
        while (isdigit(ch)) {
            Push(stack_rpn, ch);
            scanf("%c", &ch);
            if (!isdigit(ch)) {
                Push(stack_rpn, ' ');
            }
        }
        if (ch == ')')     //如果是)则一直弹出到() # (不输出
        {
            Pop(s,&e);
            while(e != '('){
                Push(stack_rpn, e);
                Push(stack_rpn, ' ');
                Pop(s,&e);
            }
        }
        else if (ch == '+' || ch== '-')
        {
            if (!StackLen(s)) {
                Push(s, ch);    // 如果空栈，则入栈，否则依次出栈
            }
            else
            {
                do
                {
                    Pop(s, &e);
                    if ('(' == e) {
                        Push(s,e);
                    }
                    else
                    {
                        Push(stack_rpn,e);
                        Push(stack_rpn, ' ');
                    }
                    
                } while (!StackLen(s) && e !='(');  //当栈空或者到了(, 注意(不输出
                Push(s, ch);
            }
            
            
        }
        else if (ch == '*' || ch == '/')
        {
            Push(s, ch);
        }
        else
            if (ch != '\n')    printf("输入错误\n");
        if (ch=='\n') {
            break;
        }else   scanf("%c", &ch);
    }
    while(StackLen(s)){
        Pop(s, &e);
        Push(stack_rpn, e);
        Push(stack_rpn, ' ');
    }
}