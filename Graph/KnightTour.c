// 回溯 骑士周游问题

#include <stdio.h>
#include <time.h>

#define CHESS_SIZE 8
#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
int Chess[CHESS_SIZE][CHESS_SIZE];

Status InitChess(){
    for(size_t i = 0; i < CHESS_SIZE; i++)
    {
        for(size_t j = 0; j < CHESS_SIZE; j++)
        {
            Chess[i][j] = 0;
        }
    }
    return OK;
}

Status ShowChess(){
        for(size_t i = 0; i < CHESS_SIZE; i++)
    {
        for(size_t j = 0; j < CHESS_SIZE; j++)
        {
            printf("%d\t",Chess[i][j]);
        }
        printf("\n");
    }
    return OK;
}

Status NextPos(int *x, int *y, int count){
    
    switch (count)
    {

        default:
            break;
    }
}


// 深度优先遍历棋盘
Status TravelChess(int x, int y, int tag){
    int flag = 0;
    int count = 0;
    int x1 = x;
    int y1 = y;
    Chess[x][y] = tag;
    if (tag == CHESS_SIZE * CHESS_SIZE) {
        ShowChess();
        return OK;
    }
    // 如果没走完，则继续走
    flag = NextPos(&x1,&y1, count);
    while(!flag && count < 7){    
        count++;
        flag = NextPos(&x1,&y1, count);
    }
    
    while(flag){
        if(TravelChess(x1,y1,tag+1))
        {
            return OK;
        }
        x1 = x;
        y1 = y;
        count++;
        flag = NextPos(&x1,&y1, count);
        while(!flag && count < 7){    
            count++;
            flag = NextPos(&x1,&y1, count);
        }
    
    }
    
}

int main(int argc, char const *argv[])
{
    InitChess();

    return 0;
}
