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
    TreeNode* ans=nullptr;
    int ansDepth=0;
    int dfs(TreeNode* root, int depth){
        if(!root){
            return 0;
        }
        int lh=dfs(root->left, depth+1);
        int rh=dfs(root->right, depth+1);
        int rooth=max(lh,rh)+1;
        if(lh==rh && ansDepth<=depth+rooth){
            ansDepth=depth+rooth;
            ans=root;
        }
        return rooth;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};

/*
    - get left,right heights
    - if lh and rh same && ansDepth<depth then ansDepth=depth, ans=root

*/


/*

class Solution {
public:

    pair<int, TreeNode*> rec(TreeNode* root){
        if(!root){
            return {0,NULL};
        }
        auto l=rec(root->left);
        auto r=rec(root->right);
        if(l.first==r.first){
            return {l.first+1,root};
        }else if(l.first>r.first){
            return {l.first+1,l.second};
        }else{
            return {r.first+1,r.second};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return rec(root).second;
    }
};


// O(N), O(N)
class Solution__2 {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> lastLevel;

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lastLevel.push_back(node);

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());

        // Move upward until one node remains
        while (deepest.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : deepest) {
                next.insert(parent[node]);
            }
            deepest = next;
        }

        return *deepest.begin();
    }
};


// O(N^2) time and O(N) space
class Solution__3 {
public:
    TreeNode* ans = NULL;
    int mini;

    void check(TreeNode* root, unordered_set<TreeNode*>& nodes, int& siz, int& count) {
        if (!root) return;
        siz++;
        if (nodes.count(root)) count++;
        check(root->left, nodes, siz, count);
        check(root->right, nodes, siz, count);
    }

    void traverse(TreeNode* root, unordered_set<TreeNode*>& nodes) {
        if (!root) return;

        int siz = 0, count = 0;
        check(root, nodes, siz, count);

        if (count == (int)nodes.size()) {
            if (siz < mini) {
                mini = siz;
                ans = root;
            }
        }

        traverse(root->left, nodes);
        traverse(root->right, nodes);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return NULL;

        mini = 1e9;
        ans = NULL;

        queue<TreeNode*> q;
        q.push(root);

        unordered_set<TreeNode*> deepestNodes;

        while (!q.empty()) {
            int sz = (int)q.size();
            unordered_set<TreeNode*> temp;

            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                temp.insert(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            deepestNodes = std::move(temp);
        }

        traverse(root, deepestNodes);
        return ans;
    }
};



// WRONG IDEA BUT TOOK TOO MUCH TIME!!! FIX OR TRY TO MOVE-ON QUICKER IF SOL IF WRONG!!!!!!!
class Solution_____WORNG_WRONG_WRONG {
public:
    TreeNode* ans=NULL;
    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }

    int minDepth(TreeNode* root, int max_depth){
        if(!root){
            return 0;
        }
        int l=INT_MAX,r=INT_MAX;
        // if(!root->left && !root->right){
        //     min_depth_at_node=1;
        // }else{
            // if(root->left){
        l=minDepth(root->left,max_depth-1);
            // }
            // if(root->right){
        r=minDepth(root->right,max_depth-1);
            // }
        // }
        if(l==max_depth-1 && r==max_depth-1){
            cout<<root->val<<endl;
            ans=root;
        }
        cout<<root->val<<" "<<l<<" "<<r<<endl;
        return min(l,r)+1;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int max_depth=depth(root);
        cout<<max_depth<<endl;
        minDepth(root,max_depth);
        return ans;
    }
};



*/