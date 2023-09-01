//
// Created by lin.chen1 on 2023/8/30.
//

#ifndef C_LEARNING_ALGRAPH_H
#define C_LEARNING_ALGRAPH_H

#include "../list/List.h"


#define MAX_VERTEX_NUM 20

typedef struct ArcNode {
    int adjVex;
    struct ArcNode *nextArc;
    int data;
} ArcNode;
typedef struct VNode {
    ArcNode *firstArc;
    int data;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct AlGraph {
    AdjList vertices;
    int vexNum, arcNum;
    int kind;
} AlGraph;

void initGraph(AlGraph &graph);

void addVNode(AlGraph &graph, int data);

void addArcNode(AlGraph &graph, int fromNode, int toNode, int data);

void topologicalSort(AlGraph &graph);

void findInDegree(AlGraph &graph, int *inDegree);

void topologicalSort(AlGraph &graph, int *&ve, List<int> &s);

void criticalPath(AlGraph &graph);

#endif //C_LEARNING_ALGRAPH_H
