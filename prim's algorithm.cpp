#include <iostream>
using namespace std;
#define MAX 999

int exmin(int* key, int* mst, int N);
int check_edge(int* edge, int* mst, int from);
void prim(int** graph, int N, int E, int S);
int main(){
    int N, E, S;
    cin >> N >> E;
    int** graph;
    graph = new int* [E];
    for (int i = 0; i < E; i ++){
        graph[i] = new int [3];
    }
    for (int i = 0; i < E; i ++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    cin >> S;
    prim(graph, N, E, S);
}

int exmin(int* key, int* mst, int N){
    int min_inx, min_val = MAX;
    for (int i = 0; i < N; i ++){
        if (key[i] < min_val && mst[i] == 0){
            min_inx = i;
            min_val = key[i];
        }
    }
    return min_inx;
}

int check_edge(int* edge, int* mst, int from){
    if (edge[0] == from+1 && mst[edge[1]-1] == 0) return edge[1]-1;
    if (edge[1] == from+1 && mst[edge[0]-1] == 0) return edge[0]-1;
    return -1;
}

void prim(int** graph, int N, int E, int S){
    int from, to, total_weight = 0;
    int mst[N], parent[N], key[N];
    for (int i = 0; i < N; i ++){
        mst[i] = 0;
        key[i] = MAX;
    }
    key[S-1] = 0;
    parent[S-1] = 0;
    for (int i = 0; i < N; i ++){
        from = exmin(key, mst, N);
        mst[from] = 1;
        for (int i = 0; i < E; i ++){
            to = check_edge(graph[i], mst, from);
            if (to != -1 && graph[i][2] < key[to]){
                key[to] = graph[i][2];
                parent[to] = from+1;
            }
        }
    }
    for (int i = 0; i < N; i ++){
        total_weight += key[i];
    }
    for (int i = 0; i < N; i ++){
        cout << parent[i] << " ";
    }
    cout << endl;
    cout << total_weight;
}
