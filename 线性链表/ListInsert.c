Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p,s;
    
    p = *L; //也学是(*L)->next
    j = 1;
    while(p->next && j<i){
        /* code */
        p = p->next;
        j++;
    }

    if (!p || j>i) {
        /* code */
        return ERROR;
    }

    s = (LinkList)malloc(sizeof(Node));
    s->data = e;

    s->next = p->next;
    p->next = s;
    
    return OK;
}