#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "quene.h"
// 本队列第一个元素存放于PFront->next




// 初始化队列
PQuene InitQuene(void){
    PQuene LinkQuene = (PQuene)malloc(sizeof(Quene));
    assert(LinkQuene);
    LinkQuene->PFront = LinkQuene->PRear = (PNode)malloc(sizeof(Node));
    assert(LinkQuene->PFront);
    assert(LinkQuene->PRear);
    LinkQuene->PFront->next = NULL;
    return LinkQuene;
}


// 队尾插入数据
Status InsertQuene(PQuene LinkQuene, ElementType var){
    
    PNode InsertNode = (PNode)malloc(sizeof(Node));
    assert(InsertNode); 
    InsertNode->data = var;
    InsertNode->next = NULL;
    LinkQuene->PRear->next = InsertNode;
    LinkQuene->PRear = InsertNode;
    
    return OK;
}


//对头删除数据，并将数据赋值var，Status返回状态码
Status DeleteQueneNode(PQuene LinkQuene, ElementType *var){
    if (LinkQuene->PFront == LinkQuene->PRear) {
        printf("队列已为空\n");
        return ERROR;
    }
    else
    {
        PNode p = (PNode)malloc(sizeof(Node));
        p = LinkQuene->PFront->next;
        *var = p->data;
        LinkQuene->PFront->next = p->next;
        if (LinkQuene->PRear == p) {
            LinkQuene->PRear = LinkQuene->PFront;
        }
        free(p);
        return OK;
    }
    
    return OK;

}

//删除整个链表
Status DeleteQuene(PQuene LinkQuene){

    assert(LinkQuene);

    while(LinkQuene->PFront){
        LinkQuene->PRear = LinkQuene->PFront->next;
        free(LinkQuene->PRear);
        LinkQuene->PFront = LinkQuene->PRear;
    }
    
    return ERROR;
}

