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

vector<int> LeftView(Node* node) {
    if(node == NULL) return {};
    map<int,int> mp;
    queue<pair<int,Node*>> q;
    q.push({0,node});
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0;i<sz;i++) {
            auto p  = q.front();
            q.pop();
            int l = p.first;
            Node* curr = p.second;
            if(mp[l]==0) {
               mp[l] = curr->val;
            }
            if(curr->left) {
                q.push({l+1,curr->left});
            }
            if(curr->right) {
                q.push({l+1,curr->right});
            }
        }
    }
    vector<int> ans;
    for(auto it : mp) {
        ans.push_back(it.second);
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

    auto ans = RightView(head);
    for(auto ele : ans) {
        cout<<ele<<" ";
    }
    cout<<endl;

return 0;
}

