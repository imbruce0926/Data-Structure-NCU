#include <iostream>

using namespace std;

    const int MAX_pts = 1000, MAX = 1000;
    int choose(int , int *, int *);

int main()
{

    int cost[MAX_pts][MAX_pts], dist[MAX_pts], found[MAX_pts];
    int pts_num, start_p, end_p;

    cin >> pts_num >> start_p >> end_p;

    for(int i = 0; i < pts_num; i++) {
        for(int j = 0; j < pts_num; j++) {
            cin >> cost[i][j];
            if(i != j && cost[i][j] == 0)
                cost[i][j] = MAX;
        }
    }

    for(int i = 0; i < pts_num; i++) {
        dist[i] = cost[start_p][i];
        found[i] = 0;
    }

    int u;
    found[start_p] = 1;

    for(int i = 0; i < pts_num - 2; i++) {
        u = choose(pts_num, dist, found);
        found[u] = 1;

        for(int w = 0; w < pts_num; w++){
            if(dist[w] > dist[u] + cost[u][w])
                dist[w] = dist[u] + cost[u][w];
        }
    }

    cout << dist[end_p];
    return 0;
}

int choose(int pts_num, int *dist, int *found) {
    int min_v, min_pos;
    min_v = MAX;

    for(int i = 0; i < pts_num; i++) {
        if(dist[i] < min_v &&  found[i] == 0){
            min_v = dist[i];
            min_pos = i;
        }
    }

    return min_pos;
}
