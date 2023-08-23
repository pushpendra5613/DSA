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

bool helper(Node* head1,Node* head2) {
    if(head1 == NULL && head2 == NULL) return true;
    if(head1 == NULL || head2 == NULL) return false;

    if(head1->val == head2->val) {
        bool ans1 = helper(head1->left,head2->right);
        bool ans2 = helper(head1->right,head2->left);
        return ans1 & ans2;
    }
    return false;
}
bool isSymmetric(Node* node) {
    return helper(node->left,node->right);
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(2);
    head->left->left = new Node(4);
    head->right->left = new Node(5);
    head->left->right = new Node(5);
    head->right->right = new Node(4);

    cout<<isSymmetric(head);

return 0;
}

