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

int Height(Node* node) {
    if(node == NULL) return 0;
    int LeftHeight = Height(node->left);
    int RightHeight = Height(node->right);

    return max(LeftHeight,RightHeight) + 1;
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(6);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    cout<<Height(head);

return 0;
}

