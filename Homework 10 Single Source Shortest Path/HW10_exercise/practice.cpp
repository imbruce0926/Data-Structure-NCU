#include <iostream>
using namespace std;

    const int MAX = 1000;
    const int MAX_PTS = 1000;

    int choose(int *, int *, int);

int main() {

    int point_num, start_p, end_p, temp;
    int cost[MAX_PTS][MAX_PTS] = {}, dist[MAX_PTS] = {}, found[MAX_PTS] = {};

    cin >> point_num >> start_p >> end_p;

    for(int i = 0; i < point_num; i++) {
        for(int j = 0; j < point_num; j++){
            cin >> cost[i][j];
            if(i != j && cost[i][j] == 0)
                cost[i][j] = MAX;
        }
    }
    for(int i = 0; i < point_num; i++) {
        dist[i] = cost[start_p][i];
        found[i] = 0;
    }

    found[start_p] = 1;

    int u;
    for(int i = 0; i < point_num - 2; i++) {
        u = choose(dist, found, point_num);
        found[u] = 1;
        for(int w = 0; w < point_num; w++) {
            if(dist[w] > dist[u] + cost[u][w])
                dist[w] = dist[u] + cost[u][w];
        }
    }

    cout << dist[end_p];
}

int choose(int *dist, int *found, int point_num) {
    int min_v = MAX, min_pos;

    for(int i = 0; i < point_num; i++) {
        if(!found[i] && dist[i] < min_v) {
            min_v = dist[i];
            min_pos = i;
        }
    }

    return min_pos;
}
