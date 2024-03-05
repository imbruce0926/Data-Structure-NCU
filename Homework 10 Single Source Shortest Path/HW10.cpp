#include <iostream>
using namespace std;

    const int MAX = 100, MAX_NODE = 100;
    int choose(int *, int *, int);

main() {
    int node_num, start_p, end_p, temp, u;

    cin >> node_num >> start_p >> end_p ;

    int cost[MAX_NODE][MAX_NODE], dist[MAX_NODE], found[MAX_NODE];

    for(int i = 0; i < node_num; i++) {
        for(int j = 0; j < node_num; j++) {
            cin >> cost[i][j];

            if(i != j && cost[i][j] == 0)
                cost[i][j] = MAX;
        }
    }

    for(int i = 0; i < node_num; i++) {
        dist[i] = cost[start_p][i];
        found[i] = 0;
    }

    // found[start_p] = 1;

    // for(int i = 0; i < node_num - 2 ; i++) {
    //     u = choose(dist, found, node_num);
    //     found[u] = 1;
    //     for(int w = 0; w < node_num ; w++) {
    //         if(dist[w] > dist[u] + cost[u][w])
    //             dist[w] = dist[u] + cost[u][w];
    //     }
    // }

    // cout << dist[end_p];
}


int choose(int *dist, int *found, int node_num) {
    int min_v = MAX, min_pos;

    for(int i = 0; i < node_num; i++) {
        if(!found[i] && dist[i] < min_v) {
            min_v = dist[i];
            min_pos = i;
        }
    }

    return min_pos;
}
