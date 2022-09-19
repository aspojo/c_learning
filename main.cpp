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
        std::cout << (char) ('a' + i) << ": " << HC[i] << std::endl;
    }
    char code[1024];
    for (int i = 0; i < 1024; ++i) {
        code[i] = 0;
    }
    Encoding(HC, "aabbcc", 6, code);
    std::cout<<"encoding: " << code << std::endl;

    char s[1024];
    Decoding(HT, len, code, s);
    std::cout<<"decoding: " << s;

    return 0;
}
