#define ERROR   0
#define OK      1
#define TRUE    1
#define FALSE   0

typedef int Status;

// 1<=i<=ListLenth(L)
// 不需要对结构体进行操作 所以不需要输入指针变量
// sqList sq - Sequential 顺序
Status GetElem(sqList L, int i, ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
    {
        return ERROR;
    }
    *e = L.data[i-1];
    
    return OK;
}
