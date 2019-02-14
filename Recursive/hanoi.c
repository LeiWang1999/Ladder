// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>

void hanio(int n, char x, char y ,char z);

static int count = 0;

int main(int argc, char const *argv[])
{
    int depth;
    printf("请输入汉诺塔的层数:");
    scanf("%d",&depth);
    hanio(depth,'x','y','z');
    printf("一共执行了%d步\n",count);
    return 0;
}



/*
-----第一个参数为需要移动的块数,第二个参数为起始柱子,第四个参数为目标柱子
# hanoi
# 移动第n个圆盘到z柱，首先要把前n-1个圆盘从x柱移动到y柱上
# 在移动n-1个圆盘到y柱上时，需要把z柱看作y柱
# 移动n-1个圆盘到y柱，需要移动n-2个圆盘从x柱移动到z柱
# 移动n-2个圆盘到z柱，需要移动n-3个圆盘从x柱移动到y柱
# .........
# 移动2个圆盘到目标柱（第三根），需要移动1个圆盘从x柱移动到中间柱
# 移动一个圆盘到目标柱（第三根），需要x柱 -> 目标柱
# 最后需要把y柱作为起始柱，x作为中间柱，z作为目标柱
*/
void hanio(int n, char x, char y ,char z){
    if (n == 1) {
        printf("%c->%c\n",x,z);  // 把 最后一个盘子 移过去
        count++;
    }
    else
    {   count++;
        hanio(n-1,x,z,y);      // 把n-1个盘子移动到 y
        printf("%c->%c\n",x,z); // 把 第n个盘子移动到 z
        hanio(n-1,y,x,z);   //把 n-1个盘子移动过到 z上
    }
}