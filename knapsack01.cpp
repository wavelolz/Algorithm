#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

pair<int, vector<int>> knapsack(int W, int N, int* weight, int* value);
int main(){
    int W, N;
    cin >> W >> N;
    int weight[N], value[N];
    for (int i = 0; i < N; i ++){
        cin >> weight[i];
    }
    for (int i = 0; i < N; i ++){
        cin >> value[i];
    }
    pair<int, vector<int> > ans = knapsack(W, N, weight, value);
    cout << ans.first << endl;
    for (int i = 0; i < ans.second.size(); i ++){
        cout << ans.second[i] << " ";
    }
}
pair<int, vector<int>> knapsack(int W, int N, int* weight, int* value){
    int current_weight = W, inx_item = N;
    int** arr; int** isselect;
    vector<int> index;
    arr = new int* [N+1];
    isselect = new int* [N+1];
    for (int i = 0; i <= N; i ++){
        arr[i] = new int [W+1];
        isselect[i] = new int [W+1];
    }
    for (int i = 0; i <= N; i ++){
        for (int j = 0; j <= W; j ++){
            arr[i][j] = 0;
            isselect[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; i ++){
        for (int j = 1; j <= W; j ++){
            if (j < weight[i-1]){
                arr[i][j] = arr[i-1][j];
                isselect[i][j] = 0;
            } else {
                if (arr[i-1][j] < value[i-1] + arr[i-1][j-weight[i-1]]){
                    arr[i][j] = value[i-1] + arr[i-1][j-weight[i-1]];
                    isselect[i][j] = 1;
                } else {
                    arr[i][j] = arr[i-1][j];
                    isselect[i][j] = 0;
                }
            }
        }
    }
    while (current_weight > 0 && inx_item > 0){
        if (isselect[inx_item][current_weight] == 1){
            index.push_back(inx_item);
            current_weight -= weight[inx_item-1];
            inx_item -= 1;
        } else {
            inx_item -= 1;
        }
    }
    sort(index.begin(), index.end());
    pair<int, vector<int> > ans = make_pair(arr[N][W], index);
    return ans;
}
