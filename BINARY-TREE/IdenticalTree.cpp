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

bool identical(Node* head1 , Node* head2) {
    if(head1 == NULL && head2 == NULL) return true;
    if(head1 == NULL || head2 == NULL) return false;

    if(head1->val == head2->val) {
        bool l = identical(head1->left,head2->left);
        bool r = identical(head1->right,head2->right);
        return l & r;
    }
    return false;
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(6);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    Node* head1 = new Node(1);
    head1->left = new Node(2);
    head1->right = new Node(3);
    head1->left->left = new Node(4);
    head1->right->left = new Node(6);
    head1->left->right = new Node(5);
    head1->right->right = new Node(7);

    cout<<identical(head,head1)<<endl;
return 0;
}

