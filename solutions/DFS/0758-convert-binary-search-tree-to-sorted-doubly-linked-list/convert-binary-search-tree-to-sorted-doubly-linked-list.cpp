/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:

    vector<Node*> v;

    void rec(Node* root){
        if(!root){
            return;
        }
        rec(root->left);
        v.push_back(root);
        rec(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root){
            return NULL;
        }
        rec(root); 
        int n=v.size();
        for(int i=0;i<n-1;i++){
            v[i]->right=v[i+1];
            v[i+1]->left=v[i];
        }
        v[0]->left=v[n-1];
        v[n-1]->right=v[0];
        return v[0];
    }
};