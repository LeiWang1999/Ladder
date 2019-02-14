#include <stdio.h>
#include "huffman.h"

int main(int argc, char const *argv[])
{
    PtrHuffmanTree codetree = buildTree("I Love xujiayi!");
    printf("成功生成树\n");
    PtrHuffmanTable codetable = buildTable(codetree);
    encode(codetable, "I Love xujiayi!");
    decode(codetree,"0011011001011101000110001110111001111101011011010010000");
    return 0;
}
