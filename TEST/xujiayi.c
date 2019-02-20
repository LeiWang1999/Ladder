#include <stdio.h>

int main(int argc, char const *argv[])
{
    double cost;
    char a[2];
	while(scanf("**** %lf %s折", &cost, a)){
        printf("价格为:%d,折扣为%s\n",cost,a);
        getchar();
    }

    return 0;
}
