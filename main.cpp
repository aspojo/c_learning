#include <iostream>
#include "huffman.h"
#include "queue"
#include "vector"
#include "list/Node.h"

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
    myQueue.push({1, 2, 3, 4});
    std::cout << myQueue.size() << std::endl;
    std::cout << myQueue.front().rchild << std::endl;
    myQueue.pop();
    std::cout << myQueue.size() << std::endl;
    std::cout << myQueue.front().rchild << std::endl;
    std::vector<char *> v;
    v.push_back("dfd");

}

void testList(){
    List<char *> list;
    Node<char *>  node;
    node.data="aaa";
    list.head= &node;
    list.size=1;
    std::cout<<list.head[7].data<<"sdfg"<< std::endl;

}
int main() {
    testHuffmanTree();
    testQueue();
    testList();
    return 0;
}
