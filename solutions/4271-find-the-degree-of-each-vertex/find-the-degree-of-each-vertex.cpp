class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        map<int,int> mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    mp[i]++;
                    mp[j]++;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            ans.push_back((mp[i])/2);
        }
        return ans;
    }
};