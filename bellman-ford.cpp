#include <iostream>
#include <climits>
using namespace std;
void bellmanford(int** graph, int V, int E, int S);
int main(){
    int V, E, S;
    cin >> V >> E;
    int** graph;
    graph = new int* [E];
    for (int i = 0; i < E; i ++){
        graph[i] = new int [3];
    }
    for (int i = 0; i < E; i ++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    cin >> S;
    bellmanford(graph, V, E, S);

}
void bellmanford(int** graph, int V, int E, int S){
    int key[V], parent[V], dtneg[V];
    int from, to, isneg = 0;
    for (int i = 0; i < V; i ++){
        key[i] = INT_MAX;
    }
    key[S-1] = 0;
    parent[S-1] = 0;
    for (int i = 0; i < V-1; i ++){
        for (int j = 0; j < E; j ++){
            from = graph[j][0];
            to = graph[j][1];
            if (key[to-1] > key[from-1] + graph[j][2]){
                key[to-1] = key[from-1] + graph[j][2];
                parent[to-1] = from;
            }
        }
    }
    for (int i = 0; i < V; i ++){
        dtneg[i] = key[i];
    }

    for (int i = 0; i < E; i ++){
        from = graph[i][0];
        to = graph[i][1];
        if (dtneg[to-1] > dtneg[from-1] + graph[i][2]){
            dtneg[to-1] = dtneg[from-1] + graph[i][2];
        }
    }
    for (int i = 0; i < V; i ++){
        if (dtneg[i] != key[i]){
            isneg = 1;
            break;
        }
    }

    if (isneg){
        cout << "There is a negative weight cycle in the graph";
    } else {
        for (int i = 0; i < V; i ++){
        cout << key[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < V; i ++){
            cout << parent[i] << " ";
        }
    }
}
