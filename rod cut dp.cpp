#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int max(int a, int b){return (a >= b) ? a : b;}
vector<vector<int > > rodcut(vector<int> price, int n);
int main(){

    vector<int> price {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = price.size();
    vector<vector<int> > a = rodcut(price, n);
    vector<int> cutway;
    cutway.reserve(n);
    int curr_len = n;
    int countc = 0;
    while (curr_len >= 1){
        int cutpoint = a.at(1).at(curr_len-1);
        curr_len -= cutpoint;
        cutway[countc] = cutpoint;
        countc ++;
    }
    cout << a[0][n] << endl;
    cout << countc << endl;
    cout << n << " = ";
    for (int i = 0; i < countc; i ++){
        cout << cutway[i] << " ";
    }


}


vector<vector<int> > rodcut(vector<int> price, int n){
    price.insert(price.begin(), 0);
    vector<vector<int> > result;
    result.resize(2, vector<int>(n+1));
    result[0][0] = 0;
    result[0][1] = 1;
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

