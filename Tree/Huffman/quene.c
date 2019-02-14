#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "quene.h"



// 初始化队列
PQuene InitQuene(void){
    PQuene LinkQuene = (PQuene)malloc(sizeof(Quene));
    assert(LinkQuene);
    LinkQuene->PFront = LinkQuene->PRear = (PNode)malloc(sizeof(Node));
    assert(LinkQuene->PFront);
    assert(LinkQuene->PRear);
    LinkQuene->PFront->next = NULL;
    LinkQuene->size = 0;
    return LinkQuene;
}


// 通过比较排序插队  
Status InsertQuene(PQuene LinkQuene, ElementType var){
    
    PNode InsertNode = (PNode)malloc(sizeof(Node));
    assert(InsertNode); 
    InsertNode->data = var;
    InsertNode->next = NULL;
/*    LinkQuene->PRear->next = InsertNode;
    LinkQuene->PRear = InsertNode;
*/
    if (LinkQuene->size == 0 || LinkQuene->PFront->next == 0) {
        LinkQuene->PFront->next = InsertNode;
        LinkQuene->PRear = InsertNode;
        LinkQuene->size++;
    }
    else
    {  
        if (var.priority <= LinkQuene->PFront->next->data.priority) {   //如果插入数据的优先级小于第一个元素
            // 把插入数据的指针指向原来的第一层,在把front的next指向插入数据
            InsertNode->next = LinkQuene->PFront->next;
            LinkQuene->PFront->next = InsertNode;
            LinkQuene->size++;
            return OK;
        }
        else
        {   PNode iterator = LinkQuene->PFront->next; // 迭代器指向队列的第一个元素
            while(iterator->next){  //到最后一个元素的时候停止
                if (var.priority <= iterator->next->data.priority) {
                    // 如果发现优先级比迭代器所指优先级要小
                    // 则把节点插入在迭代器之前所以要比较的是next
                    // 因此忽略了最后一个节点，但如果最后一个节点都不匹配
                    // 则插入队列的最末尾
                    InsertNode->next = iterator->next;
                    iterator->next = InsertNode;
                    LinkQuene->size++;
                    return OK;
                }
                iterator = iterator->next;
            }
            if (iterator->next == NULL) {
                iterator->next = InsertNode;
                InsertNode->next = NULL;
                LinkQuene->size++;
                return OK;
            }
            
        }
        
    }
    

    return OK;
}


//对头删除数据，并将数据赋值var，Status返回状态码
Status DeleteQueneNode(PQuene LinkQuene, ElementType *var){
    if (!LinkQuene->size) {
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
        LinkQuene->size--;
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

