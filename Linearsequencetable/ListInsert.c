/*
    初始条件: 假设顺序链表L已存在，并且有 1<i<L.length，
    操作结果: 在L中第i个位置之前插入新的数据元素e，L长度加1.
*/

Status ListInsert(sqList *L, int i, ElemType e )
{
    int k;
    if (L->length == MAXSIZE) {     // 顺序线性表已满
        return ERROR;
    }
    if (i<1 || i>L->length+1) {     // i 不在范围之内 第 length + 1 个之前
        return ERROR;
    }
    if (i<=L.length) {      //如果不是插在最后一个元素之后，则需要后移
        for( k=L->length-1;k>=i-1;k--)
        {
            /* code */
            L->data[k+1] = L->data[k];
        }
    }
    
    L->data[i-1] = e;
    L->length++;
    return OK;
}
