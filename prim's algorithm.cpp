#include <stdio.h>
#include <climits>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
#define MAX 999999
using namespace std;



void prim(int** graph, int V, int E, int S);
bool sortbysec(pair<int, int> a, pair<int, int> b){return a.second <= b.second;}
int ex_min(int* key, int* mst, int V);
int find_edge(int** graph, int v1, int v2, int E);
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

    prim(graph, V, E, S);
    return 0;
}

int ex_min(int* key, int* mst, int V){
    int min_val = INT_MAX, min_inx;
    for (int i = 0; i < V; i ++){
        if (mst[i] == 0 && key[i] < min_val){
            min_val = key[i];
            min_inx = i;
        }
    }
    return min_inx;
}

int find_edge(int** graph, int v1, int v2, int E){
    int vpair[2];
    if (v1 < v2){
        vpair[0] = v1;
        vpair[1] = v2;
    } else {
        vpair[0] = v2;
        vpair[1] = v1;
    }

    for (int i = 0; i < E; i ++){
        if (graph[i][0] == vpair[0] && graph[i][1] == vpair[1]){
            return graph[i][2];
        }
    }

    return -1;
}
void prim(int** graph, int V, int E, int S){
    int key[V], parent[V], mst[V];
    int next, w, total_weight = 0;

    for (int i = 0; i < V; i ++){
        key[i] = INT_MAX; // �� key ��ֵ initialize �ɟo�޴�
        mst[i] = 0;       // ߀�]�� vertex ���ҵ�
    }
    key[0] = 0;
    parent[0] = 0;


    for (int i = 0; i < V; i ++){
        next = ex_min(key, mst, V); // ��߀�]�����^�� set �e�ҳ� key ��С�� vertex
        mst[next] = 1;              // ���ҵ���
        for (int j = 0; j < V; j ++){ // update ���ҵ����c�� adjacency vertex
            w = find_edge(graph, next+1, j+1, E);  // �_�J���c֮�g�Ƿ��� path
            if (w != -1 && w < key[j] && mst[j] == 0){
                key[j] = w;
                parent[j] = next;
            }
        }
    }
    for (int i = 1; i < V; i ++){
        total_weight += find_edge(graph, i+1, parent[i]+1, E);
    }

    cout << parent[0] << " ";
    for (int i = 1; i < V; i ++){
        cout << parent[i]+1 << " ";
    }
    cout << endl;
    cout << total_weight;
}
