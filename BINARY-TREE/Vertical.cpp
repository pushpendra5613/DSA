#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
    }
};


void helper(Node* node,int v,int level,map<int,map<int,multiset<int>>> &mp) {
    if(node == NULL) return ;
    mp[v][level].insert(node->val);
    helper(node->left,v-1,level+1,mp);
    helper(node->right,v+1,level+1,mp);
}
vector<vector<int>> Vertical(Node* node) {
    if(node == NULL) return {};
    vector<vector<int>> ans;
    map<int,map<int,multiset<int>>> mp;
    helper(node,0,0,mp);
    for(auto m : mp) {
          vector<int> v;
        for(auto it : m.second) {
            for(auto ele : it.second) {
                v.push_back(ele);
            }
        }
        ans.push_back(v);

    }
    return ans;
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(6);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    auto ans = Vertical(head);

    for(auto vec : ans) {
        for(auto ele : vec) cout<<ele<<" ";
        cout<<endl;
    }
return 0;
}

