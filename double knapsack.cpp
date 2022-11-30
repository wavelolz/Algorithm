#include <iostream>
#include <bits/stdc++.h>
#include <limits>
#include <algorithm>
#include <utility>
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




    pair<int, vector<int> > ans = doubleknapsack(N, W, V, value, weight, volume);

    cout << ans.first << endl;
    cout << ans.second.size() << endl;
    cout << "(";
    for (int i = 0; i < ans.second.size()-1; i ++){
        cout <<  ans.second[i] << ",";
    }
    cout << ans.second[ans.second.size()-1] <<  ")";




}

pair<int, vector<int> > doubleknapsack(int N, int W, int V, int* value, int* weight, int* volume){
    // �гy��� N*W*V ���}�C�A�x�s�̤j���ȸ򮳨����p
    int*** ans = (int***) calloc((N+1), sizeof(int**));
    int*** pick = (int***) calloc((N+1), sizeof(int**));


    for (int i = 0; i < N+1; i ++){
        ans[i] = (int**) calloc((W+1), sizeof(int*));
        pick[i] = (int**) calloc((W+1), sizeof(int*));
    }
    for (int i = 0; i < N+1; i ++){
        for (int j = 0; j < W+1; j ++){
            ans[i][j] = (int*) calloc((V+1), sizeof(int));
            pick[i][j] = (int*) calloc((V+1), sizeof(int));
        }
    }

    for (int i = 1; i <= N; i ++){
        for (int j = 1; j <= W; j ++){
            for (int k = 1; k <= V; k ++){
                // ���έ��q����n�M�w��i�Ӫ��~�i���i�H��i�h
                // �񤣶i�h���ܳ� arr[i][j][k] ���̨θѥu��O arr[i-1][j][k]
                if (j - weight[i-1] < 0 | k - volume[i-1] < 0){
                    ans[i][j][k] = ans[i-1][j][k];
                } else {
                    // �A�λ��ȨM�w�n���n��� i �Ӫ��~��i�h
                    ans[i][j][k] = max(ans[i-1][j][k], value[i-1] + ans[i-1][j - weight[i-1]][k - volume[i-1]]);
                }
                if (ans[i][j][k] == ans[i-1][j][k]){
                    pick[i][j][k] = 0; // �o�̪�ܲ�i�Ӫ��~���n��
                } else {
                    pick[i][j][k] = 1; // �o�̪�ܲ�i�Ӫ��~�n��
                }
            }
        }
    }

    vector<int> takeobject;
    takeobject.reserve(N);
    int cun_obj = N;
    int cun_wgt = W;
    int cun_vol = V;
    while (cun_obj >= 1){
        if (pick[cun_obj][cun_wgt][cun_vol] == 1){
            takeobject.push_back(cun_obj);
            cun_wgt -= weight[cun_obj-1];
            cun_vol -= volume[cun_obj-1];
            cun_obj -= 1;
        } else {
            cun_obj -= 1;
        }
    }
    reverse(takeobject.begin(), takeobject.end());
    pair<int, vector<int> > result;
    result = make_pair(ans[N][W][V], takeobject);

    return result;

}
