//
// Created by lin.chen1 on 2023/8/30.
//
#include <iostream>
#include "AlGraph.h"

void initGraph(AlGraph &graph) {
    graph.arcNum = 0;
    graph.vexNum = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        VNode *node = &graph.vertices[i];
        node->firstArc = nullptr;
        node->data = -1;
    }
}

void addVNode(AlGraph &graph, int data) {
    auto node = &graph.vertices[graph.vexNum];
    node->data = data;
    node->firstArc = nullptr;
    graph.vexNum++;

}

void addArcNode(AlGraph &graph, int fromNode, int toNode, int data) {
    graph.arcNum++;
    auto node = (ArcNode *) malloc(sizeof(ArcNode));
    node->data = data;
    node->adjVex = toNode;
    node->nextArc = nullptr;
//    这里如果这样写,就会多创建出来一个VNode结构体，导致后面修改的并不是graph.vertices中的结构体
//    VNode vNode = graph.vertices[fromNode];
    VNode *vNode = &graph.vertices[fromNode];
    ArcNode *arc = vNode->firstArc;

    if (arc == nullptr) {
        vNode->firstArc = node;
    } else {
        while (arc->nextArc != nullptr) arc = arc->nextArc;
        arc->nextArc = node;
    }
}

void topologicalSort(AlGraph &graph) {
    int inDegree[graph.vexNum];
    findInDegree(graph, inDegree);
    List<int> stack;
    for (int i = 0; i < graph.vexNum; ++i) {
        if (inDegree[i] == 0) {
            stack.add(i);
        }
    }
    std::cout<<"topological order : ";
    while (stack.size > 0) {
        int vIndex = *stack.pop();
        VNode *vNode = &graph.vertices[vIndex];
        std::cout << graph.vertices[vIndex].data << " ";
        for (ArcNode *arc = vNode->firstArc; arc; arc = arc->nextArc) {
            int k = arc->adjVex;
            if (--inDegree[k] == 0) {
                stack.add(k);
            }
        }
    }
    std::cout <<std::endl;
}

void findInDegree(AlGraph &graph, int *inDegree) {
    for (int i = 0; i < graph.vexNum; ++i) {
        inDegree[i] = graph.vertices[i].data > -1 ? 0 : -1;
    }
    for (auto &vertice: graph.vertices) {
        ArcNode *arc = vertice.firstArc;
        while (arc != nullptr) {
            inDegree[arc->adjVex]++;
            arc = arc->nextArc;
        }
    }
}

void topologicalSort(AlGraph &graph, int *ve, List<int> &s) {
    int inDegree[graph.vexNum];
    findInDegree(graph, inDegree);
    List<int> stack;
    for (int i = 0; i < graph.vexNum; ++i) {
        if (inDegree[i] == 0) {
            stack.add(i);
        }
    }
    while (stack.size > 0) {
        int j = *stack.pop();
        s.add(j);
        VNode *vNode = &graph.vertices[j];
        // s 记录拓扑排序
        for (ArcNode *arc = vNode->firstArc; arc; arc = arc->nextArc) {
            // 当前节点的最早发生时间加上当前节点指向下一节点的弧长 大于 下一节点现有最早发生时间 则更新下一节点的最早发生时间
            // 也就是节点的最早发生时间是从根到它的最长路径
            int k = arc->adjVex;
            int dut = arc->data;
            if (ve[j] + dut > ve[k]) {
                ve[k] = ve[j] + dut;
            }
            if (--inDegree[k] == 0) {
                stack.add(k);
            }
        }
    }
}

void criticalPath(AlGraph &graph) {
    int ve[graph.vexNum], vl[graph.vexNum];
    for (int &i: ve) {
        i = 0;
    }
    List<int> s;
    topologicalSort(graph, ve, s);
    for (int & i : vl) {
        i = ve[graph.vexNum-1];
    }
    while (s.size != 0) {
        int j = *s.pop();
        for (ArcNode *arc = graph.vertices[j].firstArc; arc; arc = arc->nextArc) {
            int k = arc->adjVex;
            int dut = arc->data;
            if (vl[k] - dut < vl[j]) {
                vl[j] = vl[k] - dut;
            }

        }
    }
    std::cout << "critical path : ";

    List<VNode *> list;
    for (int i = 0; i < graph.vexNum; ++i) {
        int e = ve[i], l = vl[i];
        if (e == l ) {
            VNode *v=&graph.vertices[i];
            list.add(v);
            std::cout << graph.vertices[i].data << " ";

        }
    }
    std::cout << std::endl;

}

