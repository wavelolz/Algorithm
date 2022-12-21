#include <iostream>
#define MAX 999
using namespace std;

void FW(int** graph, int N, int E);
int main(){
    int N, E;
    cin >> N >> E;
    int** graph = new int* [E];
    for (int i = 0; i < E; i ++){
        graph[i] = new int [3];
    }
    for (int i = 0; i < E; i ++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    FW(graph, N, E);
}

void FW(int** graph, int N, int E){
    int** stp = new int* [N];
    for (int i = 0; i < N; i ++){
        stp[i] = new int [N];
    }
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            stp[i][j] = MAX;
        }
    }
    for (int i = 0; i < N; i ++){
        stp[i][i] = 0;
    }
    for (int i = 0; i < E; i ++){
        stp[graph[i][0]-1][graph[i][1]-1] = graph[i][2];
    }
    for (int k = 0; k < N; k ++){
        for (int i = 0; i < N; i ++){
            for (int j = 0; j < N; j ++){
                if (stp[i][j] > stp[i][k] + stp[k][j]){
                    stp[i][j] = stp[i][k] + stp[k][j];
                }
            }
        }
    }
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            if (stp[i][j] < MAX){
                cout << stp[i][j] << " ";
            } else {
                cout << "N" << " ";
            }
        }
        cout << endl;
    }
}
