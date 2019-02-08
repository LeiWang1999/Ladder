// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>

int Fibonacci(int n){
    if (!n)
        return 0;
    else if (1 == n)
        return 1;
    else return Fibonacci(n-1) + Fibonacci(n-2);
}


int main(int argc, char const *argv[])
{
    size_t count = 0;
    printf("请输入需要打印的斐波那契的层数");
    scanf("%d",&count);
    for(size_t i = 0; i < count; i++)
    {
        printf("%d ",Fibonacci(i));
    }
    

    return 0;
}
