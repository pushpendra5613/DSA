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

void inorder(Node* node, vector<int> &v) {
    if(node == NULL) return;
    inorder(node->left,v);
   if(node->left==NULL && node->right == NULL) v.push_back(node->val);
    inorder(node->right,v);
}
vector<int> Boundary(Node* node) {
    if(node == NULL) return {};
    queue<Node*> q;
    vector<int> l;
    q.push(node);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if(curr->left==NULL && curr->right==NULL) continue;
        l.push_back(curr->val);
        if(curr->left) {
            q.push(curr->left);
        }
        else {
            q.push(curr->right);
        }
    }

    vector<int> r;
    if(node->right)  q.push(node->right);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if(curr->left==NULL && curr->right==NULL) continue;
        r.push_back(curr->val);
        if(curr->right) {
            q.push(curr->right);
        }
        else {
            q.push(curr->left);
        }
    }

    vector<int> leaf;
    inorder(node,leaf);

    vector<int> ans = l;
    for(auto ele: leaf) ans.push_back(ele);
    reverse(r.begin(),r.end());
    for(auto ele : r) ans.push_back(ele);

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

    auto ans = Boundary(head);

    for(auto ele : ans) {
        cout<<ele<<" ";
    }
return 0;
}

