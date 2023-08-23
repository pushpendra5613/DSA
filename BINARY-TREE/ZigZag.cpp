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

vector<vector<int>> ZigZag(Node* node) {
    queue<Node*> q;
    q.push(node);

    vector<vector<int>> ans;
    bool flg = false;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> row(sz);
        for(int i=0;i<sz;i++) {
            Node* curr = q.front();
            q.pop();
            if(flg == true) {
                row[i] = curr->val;
            }
            else {
                row[sz-1-i] = curr->val;
            }

            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
        flg = !flg;
        ans.push_back(row);
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

    auto ans = ZigZag(head);

    for(auto vec : ans) {
        for(auto ele : vec) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

return 0;
}

