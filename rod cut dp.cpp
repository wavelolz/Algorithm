#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int max(int a, int b){return (a >= b) ? a : b;}
vector<vector<int > > rodcut(vector<int> price, int n);
int main(){

    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    vector<int> price(N);
    for (int i = 0; i < N; i ++){
        price[i] = arr[i];
    }
    vector<vector<int> > a = rodcut(price, N);


    vector<int> cutway;
    cutway.reserve(N);
    int curr_len = N;
    int countc = 0;
    while (curr_len >= 1){
        int cutpoint = a.at(1).at(curr_len-1);
        curr_len -= cutpoint;
        cutway[countc] = cutpoint;
        countc ++;
    }
    cout << a[0][N] << endl;
    cout << countc << endl;
    cout << N << " = ";
    for (int i = 0; i < countc-1; i ++){
        cout << cutway[i] << "+";
    }
    cout << cutway[countc-1];

}


vector<vector<int> > rodcut(vector<int> price, int n){
    price.insert(price.begin(), 0); // 先在 price 加上長度為 0 的情況
    vector<vector<int> > result;
    result.resize(2, vector<int>(n+1)); // 第一個 row 存價錢, 從 0~N
                                        // 第二個 row 存切點, 從 0~N
    result[0][0] = 0;
    result[0][1] = price[1];
    result[1][0] = 0;
    result[1][1] = 1;

    for (int i = 2; i < n + 1; i ++){
        int maxprice = INT_MIN;
        int temp;
        for (int j = 1; j <= i; j ++){
            temp = maxprice;
            maxprice = max(maxprice, price.at(j) + result.at(0).at(i-j));
            if (maxprice != temp){
                result.at(1).at(i) = j;
            }
        }
        result.at(0).at(i) = maxprice;
    }

    result[0].erase(result[0].begin());
    result[1].erase(result[1].begin());

    return result;

}

