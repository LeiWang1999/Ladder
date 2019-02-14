#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
#include "quene.h"  // 此处quene并非标准队列。为Huffman专门构建且位于同一文件夹


void traverseTree(PtrHuffmanTreeNode treeNode, PtrHuffmanTable table, int k, char code[256]){
    if (treeNode->LeftChild == NULL && treeNode->RightChild == NULL) {
        code[k] = '\0';
        PtrHuffmanLabelNode aux = (PtrHuffmanLabelNode)malloc(sizeof(HuffmanLabelNode));
        aux->code = (char*)malloc(sizeof(char)*strlen(code)+1);
        strcpy(aux->code, code);
        aux->symbol = treeNode->symbol;
        aux->next = NULL;
		printf("%c的编码是%s\n",aux->symbol,code); 
    if (!table->first) {
        table->first = aux;
        table->last = aux;
    }else
    {
        table->last->next = aux;
        table->last = aux;
    }
    }
    if (treeNode->LeftChild) {
        code[k] = '0';
        traverseTree(treeNode->LeftChild,table,k+1,code);

    }
    if (treeNode->RightChild) { 
        code[k] = '1';
        traverseTree(treeNode->RightChild,table,k+1,code);
    }

    
    
}

// 创建哈夫曼树
PtrHuffmanTree buildTree(char * inputstring){
    // 首先统计字符出现的次数
    int * probability = (int *)malloc(sizeof(int)*256);

    // 初始化出现次数数组
    for(size_t i = 0; i < 256; i++)
    {
        probability[i] = 0;
    }
    // 统计字符对应ANSCII码出现次数
    for(size_t i = 0;inputstring[i]!='\0'; i++)
    {
        probability[(unsigned char)inputstring[i]]++;
    }
    // 初始化哈夫曼队列
    PQuene HuffmanQueen = InitQuene();
    
    for(size_t i = 0; i < 256; i++)
    {
        if(probability[i]){
        printf("%c出现了%d次，对应的ANSCII码为%d\n",(char)i,probability[i],(int)i);
        }
    }

    // 形成哈夫曼队列
    for(size_t i = 0; i < 256; i++)
    {
        if(probability[i]){
            PtrHuffmanTreeNode aux = (PtrHuffmanTreeNode)malloc(sizeof(HuffmanTreeNode));
            aux->symbol = (char)i;
            aux->LeftChild = NULL;
            aux->RightChild = NULL;

            ElementType * element = (ElementType*)malloc(sizeof(ElementType));
            element->priority = probability[i];
            element->var = aux;
            
            InsertQuene(HuffmanQueen,*element);
        }
    }
    free(probability); // 出现次数数组失去用处，释放了

    // 生成哈夫曼树
    while(HuffmanQueen->size!=1){
        int priority = HuffmanQueen->PFront->next->data.priority; //第一个数据的优先级
        priority += HuffmanQueen->PFront->next->next->data.priority;
        ElementType* element_child = (ElementType *) malloc(sizeof(ElementType));
        DeleteQueneNode(HuffmanQueen,element_child);
        PtrHuffmanTreeNode LeftChild = element_child->var;
        DeleteQueneNode(HuffmanQueen,element_child);
        PtrHuffmanTreeNode RightChild = element_child->var;

        PtrHuffmanTreeNode NewNode = (PtrHuffmanTreeNode)malloc(sizeof(HuffmanLabelNode));
        NewNode ->LeftChild = LeftChild;
        NewNode ->RightChild = RightChild;

        ElementType element_insert;
        element_insert.var = NewNode;
        element_insert.priority = priority;
        InsertQuene(HuffmanQueen, element_insert);
        
    }
    PtrHuffmanTree tree = (PtrHuffmanTree)malloc(sizeof(HuffmanTree));

    ElementType element_root;
    DeleteQueneNode(HuffmanQueen,&element_root);

    tree->root = element_root.var;
    return tree;
}

PtrHuffmanTable buildTable(PtrHuffmanTree huffman_tree){
    PtrHuffmanTable table = (PtrHuffmanTable)malloc(sizeof(HuffmanTable));
    table->first = NULL;
    table->last = NULL;
    
    char code[256];
    int k = 0 ;
    traverseTree(huffman_tree->root , table,k,code);
    
    printf("%c",table->first->symbol);
    return table; 
}

void encode(PtrHuffmanTable table,char * stringtoEncode){
    PtrHuffmanLabelNode traversal;
    printf("Encoding...........\ninputstring:%s\nEncodedstring:",stringtoEncode);

    for(size_t i = 0;stringtoEncode[i] != '\0'; i++)
    {
        traversal = table->first;
        while(traversal->symbol != stringtoEncode[i]) traversal= traversal->next;
        printf("%s",traversal->code);
    }
    printf("\n");
}


void decode(PtrHuffmanTree tree, char * stringtoDecode){
    PtrHuffmanTreeNode traversal = tree->root;

    printf("\n\nDecoding.......\n\n InputString:%s\n",stringtoDecode);
    printf("decodestring:");
    for(size_t i = 0;stringtoDecode[i]!='\0'; i++)
    {
        if (traversal->LeftChild == NULL || traversal->RightChild == NULL) {
            printf("%c",traversal->symbol);
            traversal = tree->root;
        }
        if (stringtoDecode[i] == '0') {
            traversal = traversal->LeftChild;
        }
        else if (stringtoDecode[i] == '1') {
            traversal = traversal->RightChild;
        }
        else
        {
            printf("您输入了除了0和1以外的字符呢！\n");
            return;
        }
        
    }
    if (traversal->LeftChild == NULL && traversal->RightChild == NULL) {
        printf("%c",traversal->symbol);
    }
    
    
}
