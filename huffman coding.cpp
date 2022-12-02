#include <iostream>
#include <utility>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
public:
    int freq;
    Node* left = NULL;
    Node* right = NULL;
    void print_node(){
        cout << "freq :" << freq << endl;
    }
};

Node* create_node(int freq);
vector<Node*> extract_min(vector<Node*> prior_que);
vector<pair<int, vector<char> >> inorder(Node* root, char codeadd, vector<char> code, vector<pair<int, vector<char> >> &output);
// bool sortans(pair<int, vector<char> > a, pair<int, vector<char> > b){return (a.first < b.first);}

int main(){
    int N;
    cin >> N;
    int freq[N];
    for (int i = 0; i < N; i ++){
        cin >> freq[i];
    }



    vector<Node*> prior_que;
    Node* root;
    for (int i = 0; i < N; i ++){
        root = create_node(freq[i]);
        prior_que.push_back(root);
    }


    while (prior_que.size() > 1){
        prior_que = extract_min(prior_que);
    }

    vector<char> code;
    vector<pair<int, vector<char> >> output;
    output = inorder(prior_que[0], '\0', code, output);

    vector<pair<int, vector<char> >> ans;
    ans.resize(N);
    int target;
    int pos;

    for(int i = 0; i < N; i ++){
        target = output.at(i).first;
        auto it = find(freq, freq+N, target);
        pos = distance(freq, it);
        ans.at(pos) = output.at(i);
    }

    cout << N << endl;
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < ans.at(i).second.size(); j ++){
            cout << ans.at(i).second.at(j);
        }
    }






    return 0;
}


Node* create_node(int freq){
    Node* newnode = new Node();
    newnode->freq = freq;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

vector<Node*> extract_min(vector<Node*> prior_que){
    // �� freq �̤p����m
    int mininx = 0;
    int mintemp = prior_que.at(0)->freq;
    for (int i = 1; i < prior_que.size(); i ++){
        if (prior_que.at(i)->freq < mintemp){
            mininx = i;
            mintemp = prior_que.at(i)->freq;
        }
    }

    // �N freq �̤p�� node �� pointer �s�_��
    Node* minfreq = prior_que.at(mininx);
    // �N freq �̤p�� node �� pointer �q queue ������
    vector<Node*>::iterator i = prior_que.begin() + mininx;
    prior_que.erase(i);


    // �� freq �ĤG�p����m
    int semininx = 0;
    int semintemp = prior_que.at(0)->freq;
    for (int i = 1; i < prior_que.size(); i ++){
        if (prior_que.at(i)->freq < semintemp){
            semininx = i;
            semintemp = prior_que.at(i)->freq;
        }
    }
    Node* seminfreq = prior_que.at(semininx);
    vector<Node*>::iterator j = prior_que.begin() + semininx;
    prior_que.erase(j);

    // �N�̤p�M�ĤG�p�� node ���s�X���@�ӷs�� node
    Node* mergenode = new Node();
    mergenode->freq = minfreq->freq + seminfreq->freq;
    mergenode->left = minfreq;
    mergenode->right = seminfreq;

    // �N�s�� node �s�� queue ��
    prior_que.push_back(mergenode);

    return prior_que;

}

vector<pair<int, vector<char> >> inorder(Node* root, char codeadd, vector<char> code, vector<pair<int, vector<char> >> &output){
    code.push_back(codeadd);

    // �p�G�O leaf node �N output
    if (!root->left && !root->right){
        pair<int, vector<char> > ans = make_pair(root->freq, code);
        output.push_back(ans);
    }

    if (root->left){
        inorder(root->left, '0', code, output);
    }

    if (root->right){
        inorder(root->right, '1', code, output);
    }
    // sort(output.begin(), output.end(), sortans);
    return output;




}

