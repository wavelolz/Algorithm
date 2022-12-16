#include <iostream>
#include <climits>
using namespace std;

void dijkstra(int** graph, int V, int E, int S);
int ex_min(int* key, int* sss, int V);
int check_edge(int** graph, int E, int from, int to);
int main(){
    int V, E, S;
    cin >> V >> E;
    int** graph;
    graph = new int* [E];
    for (int i = 0; i < E; i ++){
        graph[i] = new int [3];
    }
    for (int i = 0; i < E; i ++){
        for (int j = 0; j < 3; j ++){
            cin >> graph[i][j];
        }
    }
    cin >> S;
    dijkstra(graph, V, E, S);
    return 0;
}

int ex_min(int* key, int* sss, int V){
    int min_val = INT_MAX;
    int min_inx;
    for (int i = 0; i < V; i ++){
        if (key[i] < min_val && sss[i] == 0){
            min_val = key[i];
            min_inx = i;
        }
    }
    return min_inx;
}

int check_edge(int** graph, int E, int from, int to){
    for (int i = 0; i < E; i ++){
        if (graph[i][0] == from && graph[i][1] == to){
            return graph[i][2];
        }
    }
    return -1;


}
void dijkstra(int** graph, int V, int E, int S){
    int key[V], parent[V], sss[V];
    int from, w, total_weight = 0;

    for (int i = 0; i < V; i ++){
        key[i] = INT_MAX;
        sss[i] = 0;
    }

    key[S-1] = 0;
    parent[S-1] = 0;

    for (int i = 0; i < V; i ++){
        from = ex_min(key, sss, V);
        sss[from] = 1;
        for (int j = 0; j < V; j ++){
            w = check_edge(graph, E, from+1, j+1);
            if (sss[j] == 0 && w != -1 && key[j] > key[from] + w){
                key[j] = key[from] + w;
                parent[j] = from+1;
            }
        }
    }

    for (int i = 0; i < V; i ++){
        cout << key[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < V; i ++){
        cout << parent[i] << " ";
    }
}
