#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
map<int, string> ans;

class Node{
public:
    int freq;
    Node* left = NULL;
    Node* right = NULL;
};

Node* create_node(int freq);
vector<Node*> huffman(vector<Node*> val);
bool sortbyfreq(Node* a, Node* b){return (a->freq <= b->freq);}
void encode(Node* tree, string str);

int main(){
    int N;
    cin >> N;
    int freq[N];
    for (int i = 0; i < N; i ++){
        cin >> freq[i];
    }
    vector<Node*> vec(N);
    for (int i = 0; i < N; i ++){
        vec[i] = new Node();
        vec[i]->freq = freq[i];
    }
    while (vec.size() > 1){
        vec = huffman(vec);
    }

    encode(vec[0], "");
    cout << N << endl;
    for (int i = 0; i < N; i ++){
        cout << ans[freq[i]] << " ";
    }
}
Node* create_node(int freq, Node* left, Node* right){
    Node* root = new Node();
    root->freq = freq;
    root->left = left;
    root->right = right;
    return root;
}
vector<Node*> huffman(vector<Node*> val){
    sort(val.begin(), val.end(), sortbyfreq);
    vector<Node*>::iterator it = val.begin();
    Node* mergenode = create_node(val[0]->freq + val[1]->freq, val[0], val[1]);
    val.erase(it);
    val.erase(it);
    val.push_back(mergenode);
    return val;
}

void encode(Node* tree, string str){
    if (tree->left == NULL && tree->right == NULL) ans.insert(pair<int, string>(tree->freq, str));
    if (tree->left) encode(tree->left, str + "0");
    if (tree->right) encode(tree->right, str + "1");
}
