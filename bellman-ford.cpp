#include <iostream>
#define MAX 999
using namespace std;

int bellmanford(int** graph, int N, int E, int S);
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
    bellmanford(graph, N, E, S);
}

int bellmanford(int** graph, int N, int E, int S){
    int key[N], parent[N];
    for (int i = 0; i < N; i ++){
        key[i] = MAX;
    }
    key[S-1] = 0;
    parent[S-1] = 0;
    for (int i = 0; i < N-1; i ++){
        for (int i = 0; i < E; i ++){
            if (key[graph[i][1]-1] > key[graph[i][0]-1] + graph[i][2]){
                key[graph[i][1]-1] = key[graph[i][0]-1] + graph[i][2];
                parent[graph[i][1]-1] = graph[i][0];
            }
        }
    }
    for (int i = 0; i < E; i ++){
        if (key[graph[i][1]-1] > key[graph[i][0]-1] + graph[i][2]){
            cout << "There is a negative weight cycle in the graph";
            return 0;
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
