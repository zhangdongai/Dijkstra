#include <stdio.h>
#include "node.h"

void discovery(GraphNode* node, int depth) {
    node->known_ = true;
    //计算每个临近节点的距离，更新到邻接表中
    for (int i = 0; i < node->adjacency_num; ++i) {
        int tmp_dis = (node->distance_ < 0 ? 0 : node->distance_) + node->neighbors_[i].weight_;
        if (graph_[node->neighbors_[i].index_]->distance_ < 0 ||
            tmp_dis < graph_[node->neighbors_[i].index_]->distance_) {
            graph_[node->neighbors_[i].index_]->distance_ = tmp_dis;
            vertexs_[node->neighbors_[i].index_].distance_ = tmp_dis;
            vertexs_[node->neighbors_[i].index_].prev_node_ = node->index_;
        }
    }
    //探索深度只能为1层，即探索到子节点就返回
    if (depth > 0)
        return;

    //探索子节点
    for (int i = 0; i < node->adjacency_num; ++i) {
        if (!graph_[node->neighbors_[i].index_]->known_ && depth <= 0)
            discovery(graph_[node->neighbors_[i].index_], depth + 1);
    }

    //临近节点探索完毕后，探索临近节点的临近节点，深度初始化为0
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