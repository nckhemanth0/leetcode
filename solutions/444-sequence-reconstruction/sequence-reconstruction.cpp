class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n=nums.size();
        vector<int> present(n+1,0);
        vector<int> indegree(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto seq: sequences){
            if(seq.size()==1){
                present[seq[0]]=1;
                continue;
            }
            for(int i=0;i<seq.size()-1;i++){
                int u=seq[i];
                int v=seq[i+1];
                present[u]=1;
                present[v]=1;
                indegree[v]++;
                adj[u].push_back(v);
            }
        }
        queue<int> q;
        for(auto x: nums){
            // if(!present[x]){
            //     return false;
            // }
            if(indegree[x]==0){
                q.push(x);
            }
        }
        int i=0;
        while(!q.empty()){
            if(q.size()>1){
                return false;
            }   
            auto u=q.front();
            q.pop();   
            if(nums[i++]!=u){
                return false;
            }          
            for(auto v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return true;
    }
};

/*

if num in seq not in nums: false
if extra numbers in nums: false

and order of topo shd match

*/