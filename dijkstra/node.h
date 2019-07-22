#pragma once

#include <malloc.h>

#define Vertexs_Num 10

typedef struct NodeInfo {
    int index_;     //�ٽ��ڵ������
    int weight_;  //�ٽ��ڵ��Ȩֵ
};

typedef struct GraphNode {
    int index_;                 //ÿһ���ڵ㶼��һ�������������㷨ʵ��
    int adjacency_num;    //�ٽ��ڵ������
    bool known_;            //�Ƿ��ѱ�̽��
    int distance_;              //���ʼ�ڵ�ľ���
    NodeInfo neighbors_[];  //��¼�ٽ��ڵ�
} GraphNode;

//�ڽӱ���¼ÿ���ڵ��Ƿ��ѱ�̽�������ʼ�ڵ����С���룬��һ���ڵ�
typedef struct Adjacency {
    int index_;
    int distance_;      //���ʼ�ڵ�ľ���
    int prev_node_;     //��һ��
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

//���þ�̬�ķ�������ÿ���ڵ���ٽ�����Ϣ������������Ȩ��
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