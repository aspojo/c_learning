#include <iostream>
#include "huffman.h"
#include "queue"

void testHuffmanTree() {
    HuffmanTree HT;
    HuffmanCode HC;
    int len = 4;
    int w[4] = {7, 5, 2, 4};
    HuffmanCoding(HT, HC, w, len);
    for (int i = 0; i < len; ++i) {
        std::cout << (char) ('a' + i) << ": " << HC[i] << std::endl;
    }
    char code[1024];
    for (char & i : code) {
        i = 0;
    }
    Encoding(HC, "aabbcc", 6, code);
    std::cout << "encoding: " << code << std::endl;

    char s[1024];
    for (char & i : s) {
        i = 0;
    }
    Decoding(HT, len, code, s);
    std::cout << "decoding: " << s << std::endl;
}

void testQueue() {
    std::queue<HTNode> myQueue;
    myQueue.push({1, 1, 1, 1});
    std::cout << myQueue.size() << std::endl;
    myQueue.pop();
    std::cout << myQueue.size() << std::endl;

}

int main() {
    testHuffmanTree();
    testQueue();
    return 0;
}
