#include <stdio.h>
#include "node.h"

void discovery(GraphNode* node, int depth) {
    node->known_ = true;
    //����ÿ���ٽ��ڵ�ľ��룬���µ��ڽӱ���
    for (int i = 0; i < node->adjacency_num; ++i) {
        int tmp_dis = (node->distance_ < 0 ? 0 : node->distance_) + node->neighbors_[i].weight_;
        if (graph_[node->neighbors_[i].index_]->distance_ < 0 ||
            tmp_dis < graph_[node->neighbors_[i].index_]->distance_) {
            graph_[node->neighbors_[i].index_]->distance_ = tmp_dis;
            vertexs_[node->neighbors_[i].index_].distance_ = tmp_dis;
            vertexs_[node->neighbors_[i].index_].prev_node_ = node->index_;
        }
    }
    //̽�����ֻ��Ϊ1�㣬��̽�����ӽڵ�ͷ���
    if (depth > 0)
        return;

    //̽���ӽڵ�
    for (int i = 0; i < node->adjacency_num; ++i) {
        if (!graph_[node->neighbors_[i].index_]->known_ && depth <= 0)
            discovery(graph_[node->neighbors_[i].index_], depth + 1);
    }

    //�ٽ��ڵ�̽����Ϻ�̽���ٽ��ڵ���ٽ��ڵ㣬��ȳ�ʼ��Ϊ0
    for (int i = 0; i < node->adjacency_num; ++i) {
        GraphNode* neigh_node = graph_[node->neighbors_[i].index_];
        if (neigh_node) {
            for (int j = 0; j < neigh_node->adjacency_num; ++j) {
                if (!graph_[neigh_node->neighbors_[j].index_]->known_)
                    discovery(graph_[neigh_node->neighbors_[j].index_], 0);
            }
        }
    }
}

void main(int argc, char** argv) {
    init_graph();
    init_adjacency();
    discovery(graph_[0], 0);

    print_adjacency();

    getchar();
}