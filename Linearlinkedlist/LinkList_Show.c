// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Static;
typedef int ElementType;

typedef struct ListNode
{
    /* data */
    ElementType data;   //链表的数据
    struct ListNode *next;     //指向下一个节点的指针
}Node,*PNode;


PNode CreateList(void);
void TraverseList(PNode List);



int main(int argc, char const *argv[])
{
    PNode List = CreateList();
    TraverseList(List);
    return 0;
}



/*--------------------创建链表---------------------
这里使用尾插法: 
1. 创建一个新的Node  PNew
2. 在PNew填入数据之后,把原本的PTail的next指向PNew
3. 将PNew的next指向Null
4. PNew变成新的PTail
-------------------------------------------------*/
PNode CreateList(void){
    int lenth;
    int var;
    // 第一步
    PNode PHead = (PNode)malloc(sizeof(Node));
    if (PHead == NULL) {
        /* code */
        printf("空间分配出错！\n");
        exit(-1);
    }
    PNode PTail = PHead;
    PTail->next = NULL;
    printf("请输入节点的个数:");
    scanf("%d",&lenth);
    PHead->data = lenth;    // 为头节点的数据赋值，其值为链表的长度
    for(int i = 0; i < lenth; i++)
    {
        PNode PNew = (PNode)malloc(sizeof(Node));
        if (PNew == NULL) {
            printf("第%d个节点分配失败",i+1);
            exit(-1);
        }
        // 第二步
        printf("请输入第%d个节点的数据:",i+1);
        scanf("%d",&var);
        PNew->data = var;
        // 第三步
        PNew->next = NULL;
        PTail->next = PNew;
        // 第四步
        PTail = PNew;
    }
    
    printf("链表创建成功.\n");
    return PHead;   //返回头指针
}


/*-----------------遍历链表----------------------
1. 创建头指针PHead指向头部。
2. 遍历链表，一直到next指向NULL
*/
void TraverseList(PNode List){
    PNode PList_Trav = List;
    int i = 0;
    if (PList_Trav == NULL) {
        printf("遍历链表失败\n");
        exit(-1);
    }
    
    while(PList_Trav !=NULL){
        printf("第%d个节点的数据为:%d\n",i,PList_Trav->data);
        PList_Trav = PList_Trav->next;
        i++;
    }
}