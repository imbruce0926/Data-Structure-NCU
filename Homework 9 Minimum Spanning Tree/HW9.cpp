#include<iostream>
#include<algorithm>
using namespace std;


    const int MAX_EDGE = 50000;
    const int MAX_NODE = 2000;

    struct edge {
        int u, v, w;
    };
    typedef struct edge edge;


    void get_list(edge *, int);
    void print_cost(edge *, int);
    bool compare(edge, edge);

int main() {

    int node_num, edge_num, s_edge_num = 0;
    int element1, element2;
    edge e_list[MAX_EDGE], s_list[MAX_EDGE];
    int groups[MAX_NODE];

    cin >> node_num >> edge_num;

    get_list(e_list, edge_num);

    sort(e_list, e_list + edge_num, compare);

    for (int i = 0; i < node_num; i++)
        groups[i] = i;

    for (int i = 0; i < edge_num; i++) {
            element1 = groups[e_list[i].u];
            element2 = groups[e_list[i].v];

        if (element1 != element2) {
            s_list[s_edge_num++] = e_list[i];

            for (int i = 0; i < node_num; i++)
                if (groups[i] == element1)
                    groups[i] = element2;
        }
    }

    print_cost(s_list, s_edge_num);

}

void get_list(edge *e_list, int edge_num) {
    for(int i = 0; i < edge_num; i++)
        cin >> e_list[i].u >> e_list[i].v >> e_list[i].w;
}

bool compare(edge a, edge b){
    return a.w < b.w;
}

void print_cost(edge *s_list, int s_edge_num) {
    int cost = 0;
    for(int i = 0; i < s_edge_num; i++)
        cost = cost + s_list[i].w;
    cout << cost;
}
