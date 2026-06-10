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

    /*
            inorder successor other way:

                            int successor(Node* curr, int k)
                            {
                                if(curr==NULL)
                                    return INT_MAX;
                                if(curr->val<=k)
                                {
                                    return successor(curr->right,k);
                                }
                                return min(successor(curr->left,k),curr->val);
                            }
    */

    void inorderSuccessor(TreeNode* root, int key, TreeNode* &inorder_successor){
        if(!root){
            return;
        }
        if(key<root->val){
            inorder_successor=root;
            inorderSuccessor(root->left,key,inorder_successor);
        }else{
            inorderSuccessor(root->right,key,inorder_successor);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }else if(root->right==NULL){
                return root->left;
            }else{
                TreeNode* inorder_successor=NULL;
                inorderSuccessor(root, root->val, inorder_successor);
                deleteNode(root, inorder_successor->val);
                inorder_successor->left=root->left;
                inorder_successor->right=root->right;
                return inorder_successor;
            }
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }

/*

                // ... inside your 2-child else block ...
                TreeNode* inorder_successor = NULL;
                inorderSuccessor(root, root->val, inorder_successor);

                // Catch the return value to fix the recursive link!
                root->right = deleteNode(root->right, inorder_successor->val); 

                inorder_successor->left = root->left;
                inorder_successor->right = root->right;

                // THE MISSING PIECE: Physically free the old node's memory
                delete root; 

                return inorder_successor;

*/



    // ============ Another method with successor and precdecessor =========

    /*
        
                class Solution {
                    public int successor(TreeNode root) {
                        root = root.right;
                        while (root.left != null) root = root.left;
                        return root.val;
                    }

                    public int predecessor(TreeNode root) {
                        root = root.left;
                        while (root.right != null) root = root.right;
                        return root.val;
                    }

                    public TreeNode deleteNode(TreeNode root, int key) {
                        if (root == null) return null;

                        if (key > root.val) root.right = deleteNode(root.right, key);
                        else if (key < root.val) root.left = deleteNode(root.left, key);
                        else {
                        if (root.left == null && root.right == null) root = null;
                        else if (root.right != null) {
                            root.val = successor(root);
                            root.right = deleteNode(root.right, root.val);
                        }
                        else {
                            root.val = predecessor(root);
                            root.left = deleteNode(root.left, root.val);
                        }
                        }
                        return root;
                    }
                }
    */
};