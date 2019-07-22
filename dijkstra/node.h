#pragma once

#include <malloc.h>

#define Vertexs_Num 10

typedef struct NodeInfo {
    int index_;     //临近节点的索引
    int weight_;  //临近节点的权值
};

typedef struct GraphNode {
    int index_;                 //每一个节点都有一个索引，方便算法实现
    int adjacency_num;    //临近节点的数量
    bool known_;            //是否已被探索
    int distance_;              //与初始节点的距离
    NodeInfo neighbors_[];  //记录临近节点
} GraphNode;

//邻接表。记录每个节点是否已被探索，与初始节点的最小距离，上一跳节点
typedef struct Adjacency {
    int index_;
    int distance_;      //与初始节点的距离
    int prev_node_;     //上一跳
} Adjacency;

Adjacency vertexs_[Vertexs_Num];

void init_adjacency() {
    for (int i = 0; i < Vertexs_Num; ++i) {
        vertexs_[i].index_ = i;
        vertexs_[i].distance_ = -1;
        vertexs_[i].prev_node_ = -1;
    }
}

void print_adjacency() {
    for (int i = 0; i < Vertexs_Num; ++i) {
        printf("%d %d %d\n", vertexs_[i].index_, vertexs_[i].distance_, vertexs_[i].prev_node_);
    }
    printf("\n");
}

GraphNode *graph_[Vertexs_Num];

//采用静态的方法构造每个节点的临近点信息，包括索引和权重
void init_graph() {
    for (int i = 0; i < Vertexs_Num; ++i) {
        graph_[i] = (GraphNode *)malloc(sizeof(GraphNode));
        graph_[i]->index_ = i;
//        graph_[i]->neighbors_ = nullptr;
        graph_[i]->adjacency_num = 0;
        graph_[i]->known_ = false;
        graph_[i]->distance_ = -1;
    }

//    graph_[0]->neighbors_ = (GraphNode*)malloc(sizeof(GraphNode) * 3);
/*    graph_[0]->adjacency_num = 3;
    graph_[0]->neighbors_[0].index_ = graph_[3]->index_;
    graph_[0]->neighbors_[0].weight_ = 2;
    graph_[0]->neighbors_[1].index_ = graph_[5]->index_;
    graph_[0]->neighbors_[1].weight_ = 3;
    graph_[0]->neighbors_[2].index_ = graph_[6]->index_;
    graph_[0]->neighbors_[2].weight_ = 1;

//    graph_[1]->neighbors_ = (GraphNode*)malloc(sizeof(GraphNode) * 2);
    graph_[1]->adjacency_num = 3;
    graph_[1]->neighbors_[0].index_ = graph_[0]->index_;
    graph_[1]->neighbors_[0].weight_ = 2;
    graph_[1]->neighbors_[1].index_ = graph_[2]->index_;
    graph_[1]->neighbors_[1].weight_ = 5;
    graph_[1]->neighbors_[2].index_ = graph_[3]->index_;
    graph_[1]->neighbors_[2].weight_ = 4;

    graph_[2]->adjacency_num = 1;
    graph_[2]->neighbors_[0].index_ = graph_[8]->index_;
    graph_[2]->neighbors_[0].weight_ = 7;

//    graph_[4]->neighbors_ = (GraphNode*)malloc(sizeof(GraphNode));
    graph_[3]->adjacency_num = 3;
    graph_[3]->neighbors_[0].index_ = graph_[2]->index_;
    graph_[3]->neighbors_[0].weight_ = 2;
    graph_[3]->neighbors_[1].index_ = graph_[7]->index_;
    graph_[3]->neighbors_[1].weight_ = 6;
    graph_[3]->neighbors_[2].index_ = graph_[8]->index_;
    graph_[3]->neighbors_[2].weight_ = 8;

    graph_[4]->adjacency_num = 1;
    graph_[4]->neighbors_[0].index_ = graph_[9]->index_;
    graph_[4]->neighbors_[0].weight_ = 4;

//    graph_[5]->neighbors_ = (GraphNode*)malloc(sizeof(GraphNode) * 2);
    graph_[5]->adjacency_num = 1;
    graph_[5]->neighbors_[0].index_ = graph_[4]->index_;
    graph_[5]->neighbors_[0].weight_ = 4;

    graph_[6]->adjacency_num = 2;
    graph_[6]->neighbors_[0].index_ = graph_[3]->index_;
    graph_[6]->neighbors_[0].weight_ = 2;
    graph_[6]->neighbors_[1].index_ = graph_[4]->index_;
    graph_[6]->neighbors_[1].weight_ = 5;

    graph_[7]->adjacency_num = 1;
    graph_[7]->neighbors_[0].index_ = graph_[9]->index_;
    graph_[7]->neighbors_[0].weight_ = 1;

    graph_[8]->adjacency_num = 1;
    graph_[8]->neighbors_[0].index_ = graph_[7]->index_;
    graph_[8]->neighbors_[0].weight_ = 3;

    graph_[9]->adjacency_num = 1;
    graph_[9]->neighbors_[0].index_ = graph_[5]->index_;
    graph_[9]->neighbors_[0].weight_ = 5;
    */

    graph_[0]->adjacency_num = 3;
    graph_[0]->neighbors_[0].index_ = graph_[1]->index_;
    graph_[0]->neighbors_[0].weight_ = 1;
    graph_[0]->neighbors_[1].index_ = graph_[3]->index_;
    graph_[0]->neighbors_[1].weight_ = 1;
    graph_[0]->neighbors_[2].index_ = graph_[4]->index_;
    graph_[0]->neighbors_[2].weight_ = 3;

    //    graph_[1]->neighbors_ = (GraphNode*)malloc(sizeof(GraphNode) * 2);
    graph_[1]->adjacency_num = 1;
    graph_[1]->neighbors_[0].index_ = graph_[2]->index_;
    graph_[1]->neighbors_[0].weight_ = 2;

    graph_[2]->adjacency_num = 1;
    graph_[2]->neighbors_[0].index_ = graph_[6]->index_;
    graph_[2]->neighbors_[0].weight_ = 3;

    graph_[4]->adjacency_num = 1;
    graph_[4]->neighbors_[0].index_ = graph_[5]->index_;
    graph_[4]->neighbors_[0].weight_ = 2;

    graph_[5]->adjacency_num = 2;
    graph_[5]->neighbors_[0].index_ = graph_[6]->index_;
    graph_[5]->neighbors_[0].weight_ = 2;
    graph_[5]->neighbors_[1].index_ = graph_[7]->index_;
    graph_[5]->neighbors_[1].weight_ = 1;

    graph_[6]->adjacency_num = 1;
    graph_[6]->neighbors_[0].index_ = graph_[8]->index_;
    graph_[6]->neighbors_[0].weight_ = 3;

    graph_[7]->adjacency_num = 1;
    graph_[7]->neighbors_[0].index_ = graph_[8]->index_;
    graph_[7]->neighbors_[0].weight_ = 2;

    graph_[8]->adjacency_num = 1;
    graph_[8]->neighbors_[0].index_ = graph_[9]->index_;
    graph_[8]->neighbors_[0].weight_ = 1;
}