#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define MAX_STRLENTH 255


typedef int Status;
typedef char* String;

int* KMP_Next(String Matched, int Matched_lenth);
int KMP_Select(String SelString, int SelString_lenth, String Matched, int Matched_lenth, int * Next);

int main(int argc, char const *argv[])
{
    char *Matched = (char *)malloc(sizeof(char)*MAX_STRLENTH);
    char *SelString = (char *)malloc(sizeof(char)*MAX_STRLENTH);
    printf("请输入原始字符串:");
    scanf("%s",SelString);
    printf("请输入匹配的字符串:");
    scanf("%s",Matched);

    printf("开始查询\n原始字符串为:%s\n搜索字符串为:%s\n",SelString,Matched);

    int Matched_lenth = strlen(Matched);
    int *Next = KMP_Next(Matched, Matched_lenth);

    int location = KMP_Select(SelString, strlen(SelString), Matched, strlen(Matched), Next);

    if(location)
    printf("您所匹配的字符串在原字符串的第%d处\n", location);
    else printf("没有您要匹配的字符串呢！\n");
    

    free(Next);
    return 0;
}



// 生成KMP的Next数组
int* KMP_Next(String Matched, int Matched_lenth){
    int *Next = (int*)malloc(sizeof(int)*(Matched_lenth));
    int j = 0;  //前缀
    int i = 1;  //后缀


    Next[0] = 0;

    while((Matched_lenth - 1)){
    // 如果匹配了就前缀后缀都自增,并赋值,如果==字符串长度,则Next数组生成完毕
    if (Matched[i] == Matched[j]) {
        j++;
        Next[i] = j;
        i++;
    }
    else
    {   //  如果Matched[i] != Matched[j]
        if (j == 0) {
            Next[i] = 0;
            i++;
        }
        else
        {
            j = Next[j-1];
        }
           
    }
    if (i == Matched_lenth) {
        break;
    }
    
    }
    return Next;
}


int KMP_Select(String SelString, int SelString_lenth, String Matched, int Matched_lenth, int * Next){
    int i = 0; //selstring index
    int j = 0; //matched index
    while(TRUE){
        if (SelString[i]==Matched[j]) { // if done match next
            i++;
            j++;
            if (j == Matched_lenth ){ 
                printf("匹配成功\n");
                return i-Matched_lenth;
            }
        }
        else    // if failed . Next
        {   
            j = Next[j];
        }
        if (i == SelString_lenth) {
            return 0;
        }
        

    }
    return i-Matched_lenth;
}

