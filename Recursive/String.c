// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>

void print(){
    char ch;
    scanf("%c",&ch);
    if (ch != '\n') {
        print();
        printf("%c",ch);
    }
}

int main(int argc, char const *argv[])
{
    printf("¿ªÊ¼ÊäÈë×Ö·û´®°É:");
    print();
    return 0;
}
