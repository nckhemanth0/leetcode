class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        // unordered_map<string,vector<string>> radj;
        unordered_map<string,int> indegree;
        unordered_set<string> inRecipes;
        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
                // radj[recipes[i]].push_back(ingredients[i][j]);
            }
            inRecipes.insert(recipes[i]);
        }
        queue<string> q;
        for(auto [k,v]: adj){
            if(indegree[k]==0){
                q.push(k);
            }
        }
        vector<string> topo;
        while(!q.empty()){
            string u=q.front();
            topo.push_back(u);
            q.pop();
            for(auto v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        unordered_set<string> inSupplies;
        for(auto x: supplies){
            inSupplies.insert(x);
        }
        unordered_map<string,int> ans;
        vector<string> final_ans;
        for(auto u: topo){
            if(inSupplies.count(u)){
                ans[u]=1;
            }
            for(auto v: adj[u]){
                if(!ans.count(v)){
                    ans[v]=ans[u];
                }else{
                    ans[v]&=ans[u];
                }
            }
            if(ans.count(u) && ans[u] && inRecipes.count(u)){
                final_ans.push_back(u);
            }
        }
        return final_ans;
    }
};