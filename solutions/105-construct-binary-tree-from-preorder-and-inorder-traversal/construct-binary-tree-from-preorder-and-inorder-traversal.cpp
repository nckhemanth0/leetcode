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

    unordered_map<int,int> mp;

    TreeNode* build(int li, int ri, int lp, int rp,  vector<int>& inorder, vector<int>& preorder){
        if(li>ri){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[lp]);
        int bp=mp[preorder[lp]];
        int left_size=bp-li;
        root->left=build(li,bp-1,lp+1,lp+left_size,inorder,preorder);
        root->right=build(bp+1,ri,lp+left_size+1,rp,inorder,preorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(0,n-1,0,n-1,inorder,preorder);
    }

    // ======= ======= ======= ======= ======= ======= ======= ======= ======= =======

    // More cleaner with fewer variables:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        root->left = arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right = arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
    TreeNode* buildTree__cleaner(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
};