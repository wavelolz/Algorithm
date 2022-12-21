#include <iostream>
#define MAX 999
using namespace std;

void dijkstra(int** graph, int N, int E, int S);
int exmin(int* sss, int* key, int N);
int main(){
    int N, E, S;
    cin >> N >> E;
    int** graph = new int* [E];
    for (int i = 0; i < E; i ++){
        graph[i] = new int [3];
    }
    for (int i = 0; i < E; i ++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    cin >> S;
    dijkstra(graph, N, E, S);
}

void dijkstra(int** graph, int N, int E, int S){
    int from;
    int sss[N], key[N], parent[N];
    for (int i = 0; i < N; i ++){
        sss[i] = 0;
        key[i] = MAX;
    }
    key[S-1] = 0;
    parent[S-1] = 0;
    for (int i = 0; i < N; i ++){
        from = exmin(sss, key, N);
        sss[from] = 1;
        for (int i = 0; i < E; i ++){
            if (graph[i][0]-1 == from && key[graph[i][1]-1] > key[graph[i][0]-1] + graph[i][2] && sss[graph[i][1]-1] == 0){
                key[graph[i][1]-1] = key[graph[i][0]-1] + graph[i][2];
                parent[graph[i][1]-1] = from+1;
            }
        }
    }
    for (int i = 0; i < N; i ++){
        cout << key[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i ++){
        cout << parent[i] << " ";
    }
}

int exmin(int* sss, int* key, int N){
    int min_val = MAX;
    int min_inx;
    for (int i = 0; i < N; i ++){
        if (key[i] < min_val && sss[i] == 0){
            min_val = key[i];
            min_inx = i;
        }
    }
    return min_inx;
}
