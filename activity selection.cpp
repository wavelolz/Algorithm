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
    int N;
    cin >> N;
    vector<int> s(N);
    vector<int> e(N);
    for (int i = 0; i < N; i ++){
        cin >> s[i];

    }
    for (int i = 0; i < N; i ++){
        cin >> e[i];
    }
    vector<pair<int, int>> ans = activityselection(s, e, N);
    cout << endl;
    cout << ans.size() << endl;
    vector<int>::iterator it;
    int pos;
    vector<int> output;
    for (int i = 0; i < ans.size(); i ++){
        it = find(s.begin(), s.end(), ans[i].first);
        pos = distance(s.begin(), it)+1;
        output.push_back(pos);
    }

    cout << "(";
    sort(output.begin(), output.end());
    for (int i = 0; i < output.size()-1; i ++){
        cout << output.at(i) << ",";
    }
    cout << output.at(output.size()-1);
    cout << ")";



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
