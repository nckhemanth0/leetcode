class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        string start="0000";
        if(target==start) return 0;

        unordered_map<string,int> dist; // working as distance and visited tracking
        unordered_map<string,int> dead;
        for(auto x: deadends){
            dead[x]=1;
        }
        queue<string> q;
        if(dead[start]){
            return -1;
        }
        q.push(start);
        dist[start]=0;
        while(!q.empty()){
            string u=q.front();
            q.pop();
            // early break optimization
            if(u==target){
                return dist[target];
            }
            for(int i=0;i<4;i++){
                for (int delta:{+1, -1}){
                    string v=u;
                    v[i]=(((u[i]-'0')+delta+10)%10)+'0';
                    if(dist.find(v)==dist.end() && !dead[v]){
                        dist[v]=dist[u]+1;
                        q.push(v);
                    }
                }
            }
        }
        return -1;
    }
};