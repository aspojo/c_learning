//
// Created by lin.chen1 on 2022/9/16.
//
#include <iostream>
#include <cstring>

#ifndef C_LEARNING_HUFFMAN_H
#define C_LEARNING_HUFFMAN_H

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;


void HuffmanCoding(HuffmanTree &huffmanTree, HuffmanCode &huffmanCode, int *w, int n) ;



#endif //C_LEARNING_HUFFMAN_H
