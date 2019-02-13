#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100

typedef int ElementType;
typedef int Status;
typedef enum{Child, Thread} Flag;

typedef struct BiTNode
{
    ElementType data;
    struct BiTNode * LeftChild;
    struct BiTNode * RightChild;
    Flag LF;    // 0 -> ChildNode 1-> FrontNode
    Flag RF;    // 0 -> ChildNode 1-> rearNode
}BiTNode, *PtrBiTNode;

// 全局变量 存放前驱结点
PtrBiTNode pre;


void CreateBinaryTree(PtrBiTNode *Tree);
void visit(ElementType data, int level);
void PreOrderTraverse(PtrBiTNode root, int level);
void MidOrderTraverse(PtrBiTNode root, int level);
void ThreadTreeInit(PtrBiTNode root);
void InitPre_Thread(PtrBiTNode root);


int main(int argc, char const *argv[])
{
    PtrBiTNode root = (PtrBiTNode)malloc(sizeof(BiTNode));
    int level = 1;
    printf("请您遵照前序遍历输入树:");
    CreateBinaryTree(&root);
    InitPre_Thread(root);
    return 0;
}

// 创建二叉树   习惯用前序遍历创建
void CreateBinaryTree(PtrBiTNode *root){
    
    char ch;
    scanf("%c", &ch);
    
    if (ch == ' ') {
        *root = NULL;
    }
    else
    {   // 前序序遍历的方法生成树
        *root = (PtrBiTNode)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        (*root)->LF = Child;
        (*root)->RF = Child;

        CreateBinaryTree(&(*root)->LeftChild);   
        CreateBinaryTree(&(*root)->RightChild);
    }
}


// 访问节点操作
void visit(ElementType data, int level){
    printf("数据%c在第%d层\n",data,level);
}

// 前序遍历二叉树
void PreOrderTraverse(PtrBiTNode root, int level){
    if (root) {
        //前序遍历顺序 根左右
        visit(root->data, level);
        PreOrderTraverse(root->LeftChild,level+1);
        PreOrderTraverse(root->RightChild, level+1);
    }
}

// 中序遍历二叉树
void MidOrderTraverse(PtrBiTNode root, int level){
    if (root) {
        // 中序遍历顺序 左根右
        MidOrderTraverse(root->LeftChild,level+1);
        visit(root->data, level);
        MidOrderTraverse(root->RightChild, level+1);
    }
}

// 利用中序遍历生成线索二叉树
void ThreadTreeInit(PtrBiTNode root){
    if (root) {
        // 中序遍历顺序 左根右
        ThreadTreeInit(root->LeftChild);  // 一路遍历左子树
        
        if (!root->LeftChild) {
            root->LF = Thread;
            root->LeftChild = pre;
        }
        if (!pre->RightChild) {
            pre->RF = Thread;
            pre->RightChild = root;         // A**B**C  Root为B，则pre为A， Root为C时，Pre为B
        }
        pre = root;
        ThreadTreeInit(root->RightChild); // 一路遍历右子树
    }
}

// 初始化Pre节点，初始化全局变量的时候没有初值容易出问题
void InitPre_Thread(PtrBiTNode root){
    PtrBiTNode p = (PtrBiTNode)malloc(sizeof(BiTNode));
    pre = p;
    pre->LF = Child;
    pre->RF = Thread;
    pre->RightChild = pre;
    if (root) {
        pre->LeftChild = root;
        ThreadTreeInit(root);   // 生成线索二叉树后,把最后的节点指向p . p的右指向Root，如果root不存在，则指向自身
        pre->RightChild = p;
        pre->RF = Thread;
    }
    else
    {
        pre->RightChild = pre;
    }
}