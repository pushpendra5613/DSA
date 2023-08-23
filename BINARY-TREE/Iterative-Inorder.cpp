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

vector<int> inorder(Node* head) {
    stack<Node*> st;
   Node* node = head;
   vector<int> result;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            result.push_back(node->val);
            node = node->right;
        }
    }
    return result;
}
int main() {

    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->right->left = new Node(6);
    head->left->right = new Node(5);
    head->right->right = new Node(7);

    auto result = inorder(head);
    for(auto ele : result) {
        cout<<ele<<" ";
    }

return 0;
}

