class Solution {
public:
    unordered_map<int, unordered_map<int,int>> mp;
    // reach m,n from 0,0
    int rec(int m, int n){
        if(m<0 || n<0){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(mp.count(m) && mp[m].count(n)){
            return mp[m][n];
        }
        return mp[m][n]=rec(m-1,n)+rec(m,n-1);
    }

    int uniquePaths(int m, int n) {
        return rec(m-1,n-1);
    }
};