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

Node* LCA(Node* node,int val1,int val2) {
    if(node == NULL) return NULL;
    if(node->val == val1 || node->val == val2) return node;
    auto l = LCA(node->left,val1,val2);
    auto r = LCA(node->right,val1,val2);

    if(l == NULL && r == NULL) return NULL;
    if(l == NULL)  return r;
    if(r == NULL) return l;

    return node;
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(6);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    auto ans = LCA(head,4,5);
    cout<<ans->val;
return 0;
}

