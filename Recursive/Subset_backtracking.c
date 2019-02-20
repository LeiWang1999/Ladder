// 问题描述 输出集合的所有子集

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;


char * init_set(int size);

Status show_subset(int i, int size, char * set);


int main(int argc, char const *argv[])
{
    int size = 0;
    printf("请输入集合的长度:");
    scanf("%d",&size);
    char* set = init_set(size);
    printf("子集为:\n");
    show_subset(0,size,set);
    return 0;
}

char * init_set(int size){
    char * set = (char *)malloc(sizeof(char)*size);
    printf("集合正在初始化....\n");
    for(size_t i = 0; i < size; i++)
    {
        set[i] = i;
    }
    printf("集合的内容为:{");
    for(size_t i = 0; i < size; i++)
    {
        printf("%d,",set[i]);
    }
    printf("\b}\n");
    return set;
}

Status show_subset(int i, int size, char* set){
    // 只需要打印出被置位的下标
    if(i==size){
        printf("{");
        for(size_t i = 0; i < size; i++)
        {
            if(set[i])
            printf("%d,",i);
        }
        printf("}\n");
    }
    else{
        set[i] = 1;
        show_subset(i+1,size,set);
        set[i] = 0;
        show_subset(i+1,size,set);
    }
}