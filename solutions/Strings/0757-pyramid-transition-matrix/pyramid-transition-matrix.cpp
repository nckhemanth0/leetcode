/*
    added bitmask optimization in my existing code!
    + encoding instead of string
            Encoding helps because it replaces a variable-length, heap-backed key with a fixed-size integer key.

            Compared to unordered_map<string, bool>:

            Hashing cost:
            string key hash is O(len(cur)) (must read every character).
            uint32_t key hash is O(1) (just mix 4 bytes).

            Memory / allocations:
            string keys often mean storing/copying the string (and sometimes heap alloc / more memory).
            uint32_t keys store 4 bytes, no heap.

            Cache locality:
            integers are stored contiguously in the hash table buckets → fewer cache misses.
            strings point to separate memory → more pointer chasing.

            Net: same algorithm, but DP lookups/inserts become much cheaper, and you do tons of them.
*/
class Solution {
public:

    int mp[7][7];
    unordered_map<uint32_t,bool> dp;

    uint32_t encode(const string &cur){
        uint32_t key = (uint32_t)cur.size();
        for(char c: cur){
            key = key*8 + (uint32_t)(c - 'A' + 1);
        }
        return key;
    }

    bool rec(int level, string &cur, string next){
        if(cur.size()==1){
            return true;
        }

        uint32_t key = 0;
        if(level==0){
            key = encode(cur);
            if(dp.count(key)){
                return dp[key];
            }
        }

        if(level==cur.size()-1){
            return rec(0,next,"");
        }

        bool ans=false;
        for(int m=mp[cur[level]-'A'][cur[level+1]-'A']; m; m&=(m-1)){
            int bit = __builtin_ctz(m);
            char x = 'A' + bit;
            next.push_back(x);
            ans |= rec(level+1, cur, next);
            next.pop_back();
            if(level==0 && ans){
                return dp[key]=true;
            }
        }

        if(level==0) return dp[key]=ans;
        return ans;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(mp,0,sizeof(mp));
        for(const auto &x: allowed){
            int a=x[0]-'A', b=x[1]-'A', c=x[2]-'A';
            mp[a][b] |= (1<<c);
        }
        return rec(0,bottom,"");
    }
};


class Solution__1 {
public:

    unordered_map<char,unordered_map<char,unordered_set<char>>> mp;
    unordered_map<string,bool> dp;

    bool rec(int level, string &cur, string next){
        if(cur.size()==1){
            return true;
        }
        if(level==0 && dp.count(cur)){
            return dp[cur];
        }
        if(level==cur.size()-1){
            return rec(0,next,"");
        }
        bool ans=false;
        for(auto x: mp[cur[level]][cur[level+1]]){
            next.push_back(x);
            ans|=rec(level+1,cur,next);
            next.pop_back();
            if(level==0 && ans){
                return dp[cur]=true;
            }
        }
        if(level==0) return dp[cur]=ans;
        return ans;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(const auto &x: allowed){
            mp[x[0]][x[1]].insert(x[2]);
        }
        return rec(0,bottom,"");
    }
};