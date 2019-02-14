#ifndef __QUENE_DEFINED__
#define __QUENE_DEFINED__

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElementType;

// 声明链表
typedef struct Node
{
    ElementType data;
    struct Node * next;
}Node, *PNode;

// 队列的元素应该指向链表的节点
typedef struct Quene
{
    PNode PFront;
    PNode PRear;
}Quene, *PQuene;

PQuene InitQuene(void);
Status InsertQuene(PQuene LinkQuene, ElementType var);
Status DeleteQueneNode(PQuene LinkQuene, ElementType *var);
Status DeleteQuene(PQuene LinkQuene);


#endif