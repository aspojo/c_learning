#include <iostream>
#include "huffman.h"
#include "queue"
#include "vector"
#include "list/List.h"

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
    for (char &i: code) {
        i = 0;
    }
    Encoding(HC, "aabbcc", 6, code);
    std::cout << "encoding: " << code << std::endl;

    char s[1024];
    for (char &i: s) {
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

void testList() {
    List<char *> list;
    for (int i = 0; i < 12; ++i) {
        char * data = (char * )malloc(10);
//        char * data = (char * )malloc(10); 正确
//        char *  data = new char[10]; 正确

//        char  data[10]; 错误
//        char data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 错误

        sprintf(data, "item %d ", i);
        list.add(data);
    }

    int size = list.size;
    for (int i = 0; i < size; ++i) {
        char ** data = list.pop();
        std::cout << "list pop: " << *data << std::endl;
        delete(data);
    }


}
void testInputOutput(){
    char c = getchar();
    putchar(c);
}
int main() {
    testHuffmanTree();
    testQueue();
    testList();
    testInputOutput();
    return 0;
}
