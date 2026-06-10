// top() is frequent
class Leaderboard {
public:
    unordered_map<int,int> mp;
    map<int,int,greater<int>> cnt;

    void addScore(int id, int score) {
        int old=0;
        if(mp.count(id)){
            old=mp[id];
            if(--cnt[old]==0) cnt.erase(old);
        }
        mp[id]=old+score;
        cnt[mp[id]]++;
    }

    int top(int K) {
        long long ans=0;
        for(auto &it: cnt){
            if(K==0) break;
            int s=it.first, f=it.second;
            int take=min(K,f);
            ans += 1LL*take*s;
            K -= take;
        }
        return (int)ans;
    }

    void reset(int id) {
        int old=mp[id];
        if(--cnt[old]==0) cnt.erase(old);
        mp.erase(id);
    }
};


// Updates are many, top() is rare.
class Leaderboard__initial {
public:
    unordered_map<int,int> mp; // userd_id, score
    Leaderboard__initial() {
    }
    
    void addScore(int playerId, int score) {
        mp[playerId]+=score;
    }
    
    int top(int K) {
        priority_queue<int,vector<int>,greater<>> pq;
        int sum=0;
        for(auto &[id,score]: mp){
            pq.push(score);
            sum+=score;
            if(pq.size()>K){
                sum-=pq.top();;
                pq.pop();
            }
        }
        return sum;
    }
    
    void reset(int playerId) {
        if(mp.count(playerId)){
            mp.erase(playerId);
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */