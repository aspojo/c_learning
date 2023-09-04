#include <iostream>
#include "huffman.h"
#include "queue"
#include "vector"
#include "list/List.h"
#include "graph/AlGraph.h"

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
        char *data = (char *) malloc(10);
//        char * data = (char * )malloc(10); 正确
//        char *  data = new char[10]; 正确

//        char  data[10]; 错误
//        char data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 错误

        sprintf(data, "item %d ", i);
        list.add(data);
    }

    int size = list.size;
    for (int i = 0; i < size; ++i) {
        char **data = list.pop();
        std::cout << "list pop: " << *data << std::endl;
        delete (data);
    }


}

void testInputOutput() {
    // Ctrl+C 就是EOF
    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    putchar('e');
    putchar('o');
    putchar('f');
}

void testAlGraph() {
    AlGraph graph ;
    initGraph(graph);
    addVNode(graph, 1000);
    addVNode(graph, 1001);
    addVNode(graph, 1002);
    addVNode(graph, 1003);
    addVNode(graph, 1004);
    addVNode(graph, 1005);
    addVNode(graph, 1006);
    addVNode(graph, 1007);
    addArcNode(graph, 0, 1, 0);
    addArcNode(graph, 1, 2, 1);
    addArcNode(graph, 1, 3, 2);
    addArcNode(graph, 2, 4, 3);
    addArcNode(graph, 3, 4, 4);
    addArcNode(graph, 4, 5, 5);
    addArcNode(graph, 4, 6, 6);
    addArcNode(graph, 5, 7, 7);
    addArcNode(graph, 6, 7, 8);

    std::cout <<"arc num : "<< graph.arcNum << "  vex num : " << graph.vexNum<<std::endl;
    topologicalSort(graph);
    criticalPath(graph);
    DFSTraverse(graph);
    BFSTraverse(graph);


}

int main() {
//    testHuffmanTree();
//    testQueue();
//    testList();
//    testInputOutput();
    testAlGraph();
    return 0;
}
