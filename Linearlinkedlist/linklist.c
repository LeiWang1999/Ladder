// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "linklist.h"



int main(int argc, char const *argv[])
{
    ElementType var;
    int index;
    int find_index;
    ElementType index_data;
    ElementType insert_data;
    int insert_pos;
    int delete_node;
    int lenth;

    printf("请输入需要创建节点的个数:");
    scanf("%d",&lenth);
    PNode List = CreateList(lenth);
    TraverseList(List);

    printf("请输入要查询的节点:");
    scanf("%d",&index);
    if(IndexList(List, index, &index_data)){
    printf("索引数据完毕,位于第%d个节点的数据为:%d\n", index, index_data);   
    }
    printf("请输入需要查询的内容:");
    scanf("%d", &var);
    if(FindList(List, var, &find_index)){
    printf("你所查询的数据%d在链表的第%d个节点\n", var, find_index);
    }

    printf("您希望插入的节点是:");
    scanf("%d",&insert_pos);
    printf("数据为:");
    scanf("%d",&insert_data);
    if (InsertList(List,insert_pos,insert_data)) {
        printf("插入数据成功\n");
        TraverseList(List);
    }

    printf("请输入要删除的节点:");
    scanf("%d",&delete_node);
    if (DeleteNode(List,delete_node)) {
        printf("删除节点成功\n");
        TraverseList(List);
    }

    if (DeleteList(List)) {
        printf("删除链表成功\n");
        TraverseList(List);
    }

    
    free(List);
    return 0;
}



/*--------------------创建链表---------------------
这里使用尾插法: 
1. 创建一个新的Node  PNew
2. 在PNew填入数据之后,把原本的PTail的next指向PNew
3. 将PNew的next指向Null
4. PNew变成新的PTail
-------------------------------------------------*/
PNode CreateList(int lenth){
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
    else
    {
     printf("整个链表的长度为%d\n",PList_Trav->data);
     PList_Trav = PList_Trav->next;
     i++;
    }
    while(PList_Trav !=NULL){
        printf("第%d个节点的数据为:%d\n",i,PList_Trav->data);
        PList_Trav = PList_Trav->next;
        i++;
    }
}

/*---------------------索引链表--------------
1. 先判断传进函数的数据的合理性
2. 索引链表
*/

Status IndexList(PNode List, int index, int * e){
   
    if (List == NULL) {
        printf("头指针为空,遍历链表失败\n");
        exit(-1);
    }
    if (index>List->data) {
        printf("索引的长度超过了链表长度\n");
        return ERROR;
    }
    else if (index < 1)
    {
        printf("索引的长度不符合规范\n");
        return ERROR;
    }
    

    PNode PIndex = List->next;
    for(int i = 1; i < index; i++)
    {   
        PIndex = PIndex->next;
    }
    *e = PIndex->data;
//    printf("索引数据完毕,位于第%d个节点的数据为:%d\n", index, PIndex->data);   
    return OK;
}


/*--------------查询链表---------------
1. 判断链表的长度
2. 从头开始遍历,直到匹配.
*/

Status FindList(PNode List, ElementType var, int *index){
    if (List == NULL) {
        printf("头指针为空，遍历链表失败\n");
        exit(-1);
    }
    int node_index = 0; // 节点的位置 
    if (List->data == 0){   // 判断整个链表的长度，如果为0，就不必要遍历了
        printf("链表的长度为0\n");
        return ERROR;
    };
    PNode PFind = List->next; 
    node_index++;

    while((PFind != NULL)&&(PFind->data!=var)){
        PFind = PFind->next;
        node_index++;

    }
    if (PFind == NULL) {
        printf("查询无果\n");
        return ERROR;
    }
    
    *index = node_index;
//    printf("你所查询的数据%d在链表的第%d个节点\n", PFind->data, node_index);
    return OK;
}


/*------------------插入链表----------------------
在所给参数pos的前面插入一个数据
1. 新建一个节点Pnew，给数据赋值
2. 把Pnew-next指向pos
3. 把pos前的节点-next指向pnew
*/
Status InsertList(PNode List, int pos, ElementType data){
    if (List == NULL) {
        printf("头指针为空, 插入链表失败\n");
        exit(-1);
    }
    if (pos<1 || pos >List->data+1) {
        printf("pos不在理论范围内, 插入链表失败\n");
        return ERROR;
    }
    PNode PList = List;
    PNode PNew = (PNode)malloc(sizeof(Node));       //#######记得要开辟空间
    PNew->data = data;
    for(int i = 0; i < pos-1; i++)
    {
        PList = PList->next;   
    }
    // 此时i的值为pos-1 PList为pos-1的节点

    PNew->next = PList->next; // 第二步
    PList->next = PNew;     // 第三步
    List->data++;
    return OK;
    
}



/*--------------------删除节点----------------
1. 遍历到 pos节点之前的节点
2. 将此节点的指针指向pos的下一个节点
3. 释放pos节点
*/
Status DeleteNode(PNode List, int pos){
    if (List == NULL) {
        printf("头指针为空, 删除节点失败\n");
        exit(-1);   
    }
    if (pos<1 || pos > List->data) {
        printf("输入的节点不在理论范围内，删除节点失败\n");
        return ERROR;
    }
    
    PNode PDele = List;
    PNode Temp;
    for(int i = 0; i < pos-1; i++)
    {
        PDele = PDele->next;
    }
    // 此时.PDele指向pos-1
    Temp = PDele->next;
    PDele->next = Temp->next;
    free(Temp);
    List->data--;
    return OK;
}



/*-------------------删除整表------------------
1. 遍历链表，释放内存
Note : 并不删除头节点
*/
Status DeleteList(PNode List){
    if (List==NULL) {
        printf("头指针为空, 删除链表失败\n");
        exit(-1);
    }
    PNode PDele = List->next;
    List->next = NULL;  // 不能忘了 否则遍历失败
    List->data = 0;
    PNode Temp = PDele;
    while(PDele!=NULL){
        Temp = PDele->next;
        free(PDele);
        PDele = Temp;
    }
    return OK;
}

