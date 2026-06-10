class Solution {
public:
    vector<vector<int>> final_ans;
    vector<int> ans;
    int n;
    void rec(int level,vector<int>& v, int target){
        if(target<0){
            return;
        }
        if(target==0){
            final_ans.push_back(ans);
        }
        for(int i=level;i<n;i++){
            if(i>level && v[i]==v[i-1]){
                continue;
            }
            ans.push_back(v[i]);
            rec(i+1,v,target-v[i]);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,target);
        return final_ans;
    }

    // ============= ============= take/nottake =============== ===============

    /*

            class Solution {
                void solve(vector<int> &candidates, int i, int n, int target, vector<vector<int>> &ans, vector<int> &temp){
                    if(target == 0){
                        ans.push_back(temp);
                        return;
                    }
                    if(i>=n || target < 0){
                        return;
                    }
                    int j = i;
                    while(j<n && candidates[j] == candidates[i]){
                        j++;
                    }
                    solve(candidates, j, n, target, ans, temp);

                    temp.push_back(candidates[i]);
                    solve(candidates, i+1, n, target-candidates[i], ans, temp);
                    temp.pop_back();
                }
            public:
                vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                    vector<vector<int>> ans;
                    vector<int> temp;

                    int n = candidates.size();
                    sort(candidates.begin(), candidates.end());

                    solve(candidates, 0, n, target, ans, temp);
                    return ans;
                }
            };
    */
};