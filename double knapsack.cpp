#include <iostream>
#include <bits/stdc++.h>

using namespace std;
pair<int, vector<int> > doubleknapsack(int N, int W, int V, int* value, int* weight, int* volumn);
int main(){
    int N, W, V;
    cin >> N >> W >> V;
    int value[N], weight[N], volume[N];
    for (int i = 0; i < N; i ++){
        cin >> value[i];
    }
    for (int i = 0; i < N; i ++){
        cin >> weight[i];
    }
    for (int i = 0; i < N; i ++){
        cin >> volume[i];
    }
    pair<int, vector<int> > result;
    result = doubleknapsack(N, W, V, value, weight, volume);
    cout << result.first << endl;
    for (int i = 0; i < result.second.size(); i ++){
        cout << result.second[i] << " ";
    }
}

pair<int, vector<int> > doubleknapsack(int N, int W, int V, int* value, int* weight, int* volume){
    int cur_wgt = W, cur_vol = V, inx_item = N;
    int*** arr = (int***) calloc((N+1), sizeof(int**));
    int*** istake = (int***) calloc((N+1), sizeof(int**));
    vector<int> pick;
    pair<int, vector<int> > result;
    for (int i = 0; i <= N; i ++){
        arr[i] = (int**) calloc((W+1), sizeof(int*));
        istake[i] = (int**) calloc((W+1), sizeof(int*));
    }
    for (int i = 0; i <= N; i ++){
        for (int j = 0; j <= W; j ++){
            arr[i][j] = (int*) calloc((V+1), sizeof(int));
            istake[i][j] = (int*) calloc((V+1), sizeof(int));
        }
    }
    for (int i = 1; i <= N; i ++){
        for (int j = 1; j <= W; j ++){
            for (int k = 1; k <= V; k ++){
                if (weight[i-1] > j || volume[i-1] > k){
                    arr[i][j][k] = arr[i-1][j][k];
                } else {
                    arr[i][j][k] = max(value[i-1] + arr[i-1][j-weight[i-1]][k-volume[i-1]], arr[i-1][j][k]);
                }
                istake[i][j][k] = (arr[i][j][k] == arr[i-1][j][k]) ? 0 : 1;
            }
        }
    }
    while (inx_item > 0){
        if (istake[inx_item][cur_wgt][cur_vol] == 1){
            pick.push_back(inx_item);
            cur_wgt -= weight[inx_item-1];
            cur_vol -= volume[inx_item-1];
            inx_item -= 1;
        } else {
            inx_item -= 1;
        }
    }
    sort(pick.begin(), pick.end());
    result = make_pair(arr[N][W][V], pick);
    return result;
}
