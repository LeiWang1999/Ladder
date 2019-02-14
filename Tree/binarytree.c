#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100

typedef int ElementType;
typedef int Status;

typedef struct BiTNode
{
    ElementType data;
    struct BiTNode * LeftChild;
    struct BiTNode * RightChild;
}BiTNode, *PtrBiTNode;

void CreateBinaryTree(PtrBiTNode *Tree);
void visit(ElementType data, int level);
void PreOrderTraverse(PtrBiTNode root, int level);

int main(int argc, char const *argv[])
{
    PtrBiTNode root = (PtrBiTNode)malloc(sizeof(BiTNode));
    int level = 1;
    printf("请您遵照前序遍历输入树:");
    CreateBinaryTree(&root);
    PreOrderTraverse(root, level);
    return 0;
}

// 创建二叉树
void CreateBinaryTree(PtrBiTNode *root){
    
    char ch;
    scanf("%c", &ch);
    
    if (ch == ' ') {
        *root = NULL;
    }
    else
    {   // 前序遍历的方法生成树
        *root = (PtrBiTNode)malloc(sizeof(BiTNode));
        (*root)->data = ch;
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
        //前序遍历顺序
        visit(root->data, level);// 先访问根节点
        PreOrderTraverse(root->LeftChild,level+1);
        PreOrderTraverse(root->RightChild, level+1);
    }
}