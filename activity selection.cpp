#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <utility>
#include <algorithm>

using namespace std;


vector<pair<int, int>> activityselection(vector<int> s, vector<int> e, int n);
bool sortbysec(const pair<int, int> a, const pair<int, int> b){return a.second <= b.second;}
bool sortdesc(const pair<int, int> a, const pair<int, int>b){return a.first >= b. first;}
int main(){
    int n = 11;
    vector<int> s {1,3,0,5,3,5,6,8,8,9,12};
    vector<int> e {4,5,6,7,8,9,10,11,12,13,14};
    vector<pair<int, int>> ans = activityselection(s, e, n);
    for (int i = 0; i < ans.size(); i ++){
        cout << ans[i].first << " @ " << ans[i].second << endl;
    }
}

vector<pair<int, int>> activityselection(vector<int> s, vector<int> e, int n){
    vector<pair<int, int>> act;
    for(int i = 0; i < s.size(); i ++){
        pair<int, int> temp = make_pair(s[i], e[i]);
        act.push_back(temp);
    }
    sort(act.begin(), act.end(), sortdesc);
    vector<pair<int, int>> ans;
    /*
    for (int i = 0; i < act.size(); i ++){
        cout << act[i].first << " @ " << act[i].second << endl;
    }
    */

    ans.push_back(act[0]);
    int current_start = act[0].first;
    for (int i = 1; i < s.size(); i ++){
        if (act[i].second <= current_start){
            ans.push_back(act[i]);
            current_start = act[i].first;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;


}
