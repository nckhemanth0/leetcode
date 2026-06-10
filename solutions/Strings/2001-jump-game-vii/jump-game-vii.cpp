class Solution {
public:

    vector<int> dp;

    bool rec(int level, int &minJump, int &maxJump, string &s, int &n){
        if(s[level]=='1' || level>=n){
            return false;
        }
        if(level==n-1){
            return true;
        }
        if(dp[level]!=-1){
            return dp[level];
        }
        bool ans=false;
        for(int i=level+minJump;i<=min(level+maxJump,n-1);i++){
            ans|=(rec(i,minJump,maxJump,s,n));
        }
        return dp[level]=ans;
    }

    bool canReach__(string s, int minJump, int maxJump) {
        int n=s.length();
        cout<<n<<endl;
        dp.resize(n,-1);
        return rec(0,minJump,maxJump,s,n);
    }

    bool canReach__BFS_QUEUEU(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[0] == '1' || s[n - 1] == '1') return false;

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        int farthest = 0;  // highest index we've already expanded

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            cout<<farthest<<endl; // last index in queue that's pushed so far
            int start = max(i + minJump, farthest + 1);
            int end   = min(i + maxJump, n - 1);
            cout<<i<<" "<<start<<" "<<end<<endl;
            for (int j = start; j <= end; ++j) {
                if (s[j] == '0' && !vis[j]) {
                    if (j == n - 1) return true;
                    vis[j] = true;
                    q.push(j);
                }
            }

            farthest = max(farthest, end);
        }
        return vis[n - 1];
    }

    bool canReach(string s, int minJ, int maxJ) {
        int n = s.size();
        vector<int> ok(n, 0);
        ok[0] = (s[0]=='0');
        int window = 0;

        for (int i = 1; i < n; ++i) {
            // cout<<i<<" "<<window;
            if (i - minJ >= 0) window += ok[i - minJ];
            if (i - maxJ - 1 >= 0) window -= ok[i - maxJ - 1];
            if (s[i]=='0' && window > 0) ok[i] = 1;
            // cout<<"\t\t => \t\t"<<i<<" "<<window<<endl;
        }
        return ok[n - 1];
    }



};