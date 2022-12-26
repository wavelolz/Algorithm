#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void rodcut(int* val, int N);
int main(){
    int N;
    cin >> N;
    int val[N];
    for (int i = 0; i < N; i ++){
        cin >> val[i];
    }
    rodcut(val, N);
}

void rodcut(int* val, int N){
    int maxprice, temp, total_price = 0, cur_len = N;
    vector<int> cutway;
    int** arr = new int* [2];
    for (int i = 0; i < 2; i ++){
        arr[i] = new int [N];
    }
    for (int i = 0; i < N; i ++){
        arr[0][i] = val[i];
        arr[1][i] = i+1;
    }
    for (int i = 1; i < N; i ++){
        maxprice = arr[0][i];
        for (int j = 1; j <= floor((i+1) / 2); j ++){
            temp = maxprice;
            maxprice = max(maxprice, val[j-1] + arr[0][i-j]);
            if (temp != maxprice) arr[1][i] = j;
        }
        arr[0][i] = maxprice;
    }
    while (cur_len > 0){
        cutway.push_back(arr[1][cur_len-1]);
        cur_len -= arr[1][cur_len-1];
    }
    for (int i = 0; i < cutway.size(); i ++){
        total_price += arr[0][cutway[i]-1];
    }
    cout << total_price << endl;
    cout << cutway.size() << endl;
    cout << N << " = ";
    for (int i = 0; i < cutway.size()-1; i ++){
        cout << cutway[i] << "+";
    }
    cout << cutway[cutway.size()-1];
}
