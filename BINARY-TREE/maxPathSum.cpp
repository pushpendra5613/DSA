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

int helper(Node* node,int &maxSum) {
    if(node == NULL) return 0;
    int LeftSum = helper(node->left,maxSum);
    int RightSum = helper(node->right,maxSum);

    maxSum = max(maxSum , node->val + LeftSum + RightSum);
    return max(LeftSum,RightSum) + node->val ;
}

int maxPathSum(Node* node) {
    int sum = 0;
    int val = helper(node,sum);
    return sum;
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(6);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    cout<<maxPathSum(head)<<endl;
return 0;
}

