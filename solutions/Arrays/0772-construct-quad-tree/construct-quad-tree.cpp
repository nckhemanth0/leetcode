/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    pair<bool,bool> check(int rs,int re, int cs, int ce, vector<vector<int>>& grid){
        bool leaf=1,val=grid[rs][cs];
        for(int i=rs;i<=re;i++){
            if(leaf==0){
                break;
            }
            for(int j=cs;j<=ce;j++){
                if(leaf==0){
                    break;
                }
                leaf=leaf&(grid[i][j]==grid[rs][cs]);
            }
        }
        return {leaf,val};
    }

    Node* create(int rs,int re, int cs, int ce, vector<vector<int>>& grid){
        pair<bool,bool> x=check(rs,re,cs,ce,grid);
        bool leaf=x.first, val=x.second;
        Node* root=new Node(val,leaf);
        if(leaf){
            return root;
        }else{
            root->topLeft=create(rs,(rs+re)/2,cs,(cs+ce)/2,grid);
            root->topRight=create(rs,(rs+re)/2,(cs+ce)/2+1,ce,grid);
            root->bottomLeft=create((rs+re)/2+1,re,cs,(cs+ce)/2,grid);
            root->bottomRight=create((rs+re)/2+1,re,(cs+ce)/2+1,ce,grid);
            return root;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return create(0,n-1,0,n-1,grid);
    }


    // =========== ============ OPIMIZED MY CODE ================
    /*
                    class Solution {
                    public:
                        Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
                            // Return a leaf node if the matrix size is one.
                            if (length == 1) {
                                return new Node(grid[x1][y1], true);
                            }
                            
                            // Recursive calls to the four sub-matrices.
                            Node* topLeft = solve(grid, x1, y1, length / 2);
                            Node* topRight = solve(grid, x1, y1 + length / 2, length / 2);
                            Node* bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
                            Node* bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);
                                
                            // If the four returned nodes are leaf and have the same values
                            // Return a leaf node with the same value.
                            if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf
                            && topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val 
                            && bottomLeft -> val == bottomRight -> val) {
                                return new Node(topLeft -> val, true);
                            }
                            
                            // If the four nodes aren't identical, return non-leaf node with corresponding child pointers.
                            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
                        }
                        
                        Node* construct(vector<vector<int>>& grid) {
                            return solve(grid, 0, 0, grid.size());
                        }
                    };
    */
};