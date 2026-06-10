/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }

    // ====== ========== ITERATIVE ======== ========

    bool isSameTree__iterative(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> queue;
        queue.push({p,q});
    
        while(!queue.empty()) {
            p = queue.front().first;
            q = queue.front().second;
            queue.pop();
            
            if (p == NULL && q == NULL) continue;
            if (p == NULL || q == NULL) return false;
            if (p->val != q->val) return false;
            
            queue.push({p->left,q->left});
            queue.push({p->right,q->right});
        }
        return true;
    }
};