#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

pair<vector<vector<int> >, vector<vector<int> >> knapsack(int n, int w, vector<int> weight, vector<int> value);
int main(){
    int N = 7;
    int W = 170;
    vector<int> weight = {41,50,49,59,55,57,60};
    vector<int> value = {170,442,525,511,593,546,617};
    pair<vector<vector<int> >, vector<vector<int> >> ans = knapsack(N, W, weight, value);
    vector<int> take;
    int cw = W;
    for (int i = N; i > 0; i --){
        if (ans.second.at(i).at(cw) == 1){
            take.push_back(i);
            cw -= weight.at(i-1);
        }
    }
    reverse(take.begin(), take.end());
    cout << "最大可獲得價值為: " << ans.first.at(N).at(W) << endl;
    cout << "要拿的物品為: ";
    for (int i = 0; i < take.size(); i ++){
        cout << take.at(i) << " ";
    }
}

pair<vector<vector<int> >, vector<vector<int> >> knapsack(int n, int w, vector<int> weight, vector<int> value){
    vector<vector<int> > arr;
    arr.resize((n+1), vector<int>(w+1));
    vector<vector<int> > takeornot;
    takeornot.resize((n+1), vector<int>(w+1));
    for (int i = 1; i <= n; i ++){
        int maxvalue = INT_MIN;
        for (int j = 1; j <= w; j ++){
            if (j - weight[i-1] < 0){
                arr.at(i).at(j) = arr.at(i-1).at(j); // 確認多放一個後重量夠不夠，不夠的話最佳解就會是少一個物品的最佳解
            }
            else{
                // 決定要不要把這個物品放進去
                arr.at(i).at(j) = max(arr.at(i-1).at(j), value.at(i-1) + arr.at(i-1).at(j-weight.at(i-1)));
                if (arr.at(i).at(j) == arr.at(i-1).at(j)){
                    takeornot.at(i).at(j) = 0;
                } else {
                    takeornot.at(i).at(j) = 1;
                }
            }
            //cout << arr[i][j] << " ";
        }
        //cout << endl;
    }
    pair<vector<vector<int> >, vector<vector<int> >> ans = make_pair(arr, takeornot);
    return ans;

}
