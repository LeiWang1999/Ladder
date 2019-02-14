#if !defined(__HUFFMAN_DEFINED__)
#define __HUFFMAN_DEFINED__

typedef struct HuffmanTreeNode
{   
    char symbol;                        // symbol指的是 存放的字符
    struct HuffmanTreeNode * LeftChild;
    struct HuffmanTreeNode * RightChild;
}HuffmanTreeNode, *PtrHuffmanTreeNode;  // 霍夫曼树的节点 

typedef struct HuffmanTree
{
    PtrHuffmanTreeNode root;
}HuffmanTree,*PtrHuffmanTree;  // 霍夫曼树的根节点


typedef struct HuffmanLabelNode
{
    char symbol;    // 存放的字符
    char * code;    // 存档字符串编码
    struct HuffmanLabelNode * next;
}HuffmanLabelNode, *PtrHuffmanLabelNode;

typedef struct HuffmanTable
{
    PtrHuffmanLabelNode first;
    PtrHuffmanLabelNode last;
}HuffmanTable,*PtrHuffmanTable;

PtrHuffmanTree buildTree(char * inputstring);
PtrHuffmanTable buildTable(PtrHuffmanTree huffman_tree);
void encode(PtrHuffmanTable table, char * stringtoEncode);
void decode(PtrHuffmanTree tree, char * stringtoDecode);

#endif // __HUFFMAN_DEFINED__
