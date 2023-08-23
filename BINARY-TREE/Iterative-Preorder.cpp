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



vector<int> preorder(Node* head) {
    stack<Node*> st;
    vector<int> result;
    if(head == NULL) return result;
    st.push(head);

    while(!st.empty()) {
        Node* root = st.top();
        st.pop();
        result.push_back(root->val);
        if(root->right) {
            st.push(root->right);
        }
        if(root->left) {
            st.push(root->left);
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

    auto result = preorder(head);
    for(auto ele : result) {
        cout<<ele<<" ";
    }

return 0;
}

