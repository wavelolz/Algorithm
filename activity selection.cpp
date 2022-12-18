#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> actselection(int N, int* s, int* e);
bool sortbysec(pair<int, int> a, pair<int, int> b){return a.second < b.second;}
int main(){
    int N;
    cin >> N;
    int s[N], e[N];
    for(int i = 0; i < N; i ++){
        cin >> s[i];
    }
    for (int i = 0; i < N; i ++){
        cin >> e[i];
    }
    vector<int> ans;
    ans = actselection(N, s, e);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i ++){
        cout << ans[i] << " ";
    }
}
vector<int> actselection(int N, int* s, int* e){
    int cur_finish = -1;
    vector<pair<int, int> > act;
    vector<pair<int, int> > select;
    vector<int> sltinx;
    for (int i = 0; i < N; i ++){
        act.push_back(make_pair(s[i], e[i]));
    }
    sort(act.begin(), act.end(), sortbysec);
    for (int i = 0; i < N; i ++){
        if (act[i].first >= cur_finish){
            select.push_back(act[i]);
            cur_finish = act[i].second;
        }
    }
    for (int i = 0; i < select.size(); i ++){
        for (int j = 0; j < N; j ++){
            if (select[i].first == s[j] && select[i].second == e[j]){
                sltinx.push_back(j+1);
                break;
            }
        }
    }
    return sltinx;
}
