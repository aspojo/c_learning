//
// Created by lin.chen1 on 2022/9/16.
//

#include "huffman.h"

void Select(HuffmanTree &ht, int i, int &s1, int &s2) {
    int min=INT_MAX;
    for (int j = 0; j < i; ++j) {
        if (ht[j].parent == 0 && ht[j].weight < min) {
            s1 = j;
        }
    }
    min=INT_MAX;
    for (int j = 0; j < i; ++j) {
        if (ht[j].parent == 0 &&j != s1 && ht[j].weight < min) {
            s2 = j;
        }
    }
    std::cout <<"select: "<< s1 << ' ' << s2 << std::endl;
}

void HuffmanCoding(HuffmanTree &huffmanTree, HuffmanCode &huffmanCode, int *w, int n) {
    if (n <= 1)return;
    int m = 2 * n - 1;
    huffmanTree = (HuffmanTree) malloc(m * sizeof(HTNode));
    HuffmanTree p;
    int i;
    for (p = huffmanTree, i = 0; i < n; i++, p++, w++) *p = {*w, 0, 0, 0,};
    for (; i < m; i++, p++) *p = {0, 0, 0, 0};
    for (i = n; i < m; ++i) {
        // 构造 huffman tree
        int s1 = 0, s2 = 0;
        Select(huffmanTree, i, s1, s2);
        huffmanTree[s1].parent = i;
        huffmanTree[s2].parent = i;
        huffmanTree[i].weight = huffmanTree[s1].weight + huffmanTree[s2].weight;
        huffmanTree[i].lchild = s2;
        huffmanTree[i].rchild = s1;
    }
    huffmanCode = (HuffmanCode) malloc((n + 1) * sizeof(HuffmanCode));
    char *tmp = (char *) malloc(n * sizeof(char));
    tmp[n - 1] = '\0';
    for (int i = 0; i <n; ++i) {
        int c = i;
        int p = huffmanTree[i].parent;
        int end = n - 1;
        while (p != 0) {
            tmp[--end] = huffmanTree[p].lchild == c ? '0' : '1';
            c = p;
            p = huffmanTree[p].parent;
        }
        huffmanCode[i] = (char *) malloc((n - end) * sizeof(char));
        strcpy(huffmanCode[i], &tmp[end]);
    }
    free(tmp);

}
