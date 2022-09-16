//
// Created by lin.chen1 on 2022/9/16.
//

#ifndef C_LEARNING_HUFFMAN_H
#define C_LEARNING_HUFFMAN_H

#include <iostream>
#include <cstring>

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;


void HuffmanCoding(HuffmanTree &huffmanTree, HuffmanCode &huffmanCode, int *w, int n) ;

void Encoding(HuffmanCode huffmanCode, char * str,int strLen,char * code);

#endif //C_LEARNING_HUFFMAN_H
