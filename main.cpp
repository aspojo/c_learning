#include <iostream>
#include <cstring>
#include "huffman.h"

int main() {
    HuffmanTree HT;
    HuffmanCode HC;
    int len = 4;
    int w[4] = {7, 5, 2, 4};
    HuffmanCoding(HT, HC, w, len);
    for (int i = 0; i < len; ++i) {
        std::cout << HC[i]<<std::endl;
    }
    return 0;
}
