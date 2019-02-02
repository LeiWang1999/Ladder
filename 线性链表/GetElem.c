#define ERROR   0
#define OK      1
#define TRUE    1
#define FALSE   0

typedef int Status;

Status GetElem(LinkList L, int i, ElemType *e)
{
    int number_count;
    LinkList p;
    
    p = L->next;

    while(p && number_count<i){
        p = p->next;
        number_count++;
    }
    
    if (!p || number_count>i) {
       return ERROR;
    }
    
    *e = p->data;

    return OK;
}
