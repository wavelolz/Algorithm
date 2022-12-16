#include <iostream>
#include <climits>
#define MAX 999
using namespace std;

void FW(int** graph, int V, int E);
int main(){
    int V, E;
    cin >> V >> E;
    int** graph;
    graph = new int* [E];
    for (int i = 0; i < E; i ++){
        graph[i] = new int [3];
    }
    for (int i = 0; i < E; i ++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    FW(graph, V, E);
}
void FW(int** graph, int V, int E){
    int** stp;
    stp = new int* [V];
    for (int i = 0; i < V; i ++){
        stp[i] = new int [V];
    }
    for (int i = 0; i < V; i ++){
        for (int j = 0; j < V; j ++){
            stp[i][j] = MAX;
        }
    }
    for (int i = 0; i < E; i ++){
        stp[graph[i][0]-1][graph[i][1] - 1] = graph[i][2];
    }
    for (int i = 0; i < V; i ++){
        stp[i][i] = 0;
    }
    for (int k = 0; k < V; k ++){
        for (int i = 0; i < V; i ++){
            for (int j = 0; j < V; j ++){
                if (stp[i][j] > stp[i][k] + stp[k][j]){
                    stp[i][j] = stp[i][k] + stp[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i ++){
        for (int j = 0; j < V; j ++){
            if (stp[i][j] != MAX){
                cout << stp[i][j] << " ";
            } else {
                cout << "N" << " ";
            }
        }
        cout << endl;
    }
}
