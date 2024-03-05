#include <iostream>
#include <algorithm>
using namespace std;

    struct edge {
        int u, v, w;
    };
    typedef struct edge edge;

    const int MAX_NODE = 2000;
    const int MAX_EDGE = 5000;
    void get_list(edge *, int);
    void init_group(int *, int);
    bool compare(edge, edge);
    void print_cost(edge *, int);

int main()
{
    edge edge_list[MAX_EDGE], s_edgelist[MAX_EDGE];
    int node_num, edge_num, s_edge_num = 0;
    int node1, node2, group[MAX_NODE];

    cin >> node_num >> edge_num;

    get_list(edge_list, edge_num);
    sort(edge_list, edge_list + edge_num, compare);
    init_group(group, node_num);

    for(int i = 0; i < edge_num; i++){
        node1 = group[edge_list[i].u];
        node2 = group[edge_list[i].v];
        if(node1 != node2) {
            s_edgelist[s_edge_num++] = edge_list[i];
            for(int k = 0; k < node_num; k++) {
                if(group[k] == node1)
                    group[k] = node2;
            }
        }
    }

    print_cost(s_edgelist, s_edge_num);

    return 0;
}

void get_list(edge *edge_list, int edge_num) {
    for(int i = 0; i < edge_num; i++)
        cin >> edge_list[i].u >> edge_list[i].v >> edge_list[i].w;
}

void init_group(int *group, int node_num) {
    for(int i = 0; i < node_num; i++)
        group[i] = i;
}

bool compare(edge a, edge b) {
    return a.w < b.w;
}

void print_cost(edge *s_edgelist, int s_edge_num) {
    int cost = 0;
    for(int i = 0; i < s_edge_num; i++) {
        cost = cost + s_edgelist[i].w;
    }
    cout << cost;
}
