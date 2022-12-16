#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

int** rodcut(int* arr, int N);
int main(){
    int N, current_len, c = 0;
    cin >> N;
    int arr[N], cutway[N];
    for (int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    int** result;
    result = rodcut(arr, N);
    current_len = N;
    while (current_len > 0){
        cutway[c] = result[1][current_len-1];
        current_len -= result[1][current_len-1];
        c += 1;
    }
    cout << result[0][N-1] << endl;
    cout << c << endl;
    cout << N << "=";
    for (int i = 0; i < c-1; i ++){
        cout << cutway[i] << "+";
    }
    cout << cutway[c-1];
}

int** rodcut(int* arr, int N){
    int maxprice, rodlen, temp;
    int** result = new int* [N];
    for (int i = 0; i < N; i ++){
        result[i] = new int [N];
    }
    for (int i = 0; i < N; i ++){
        result[1][i] = i+1;
    }
    result[0][0] = arr[0];
    for (int i = 1; i < N; i ++){
        maxprice = arr[i];
        for (int j = 1; j <= floor((i+1) / 2); j ++){
            temp = maxprice;
            maxprice = max(maxprice, arr[j-1] + arr[i-j]);
            if (temp != maxprice){result[1][i] = j;}
        }
        result[0][i] = maxprice;
    }
    return result;
}

