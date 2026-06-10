class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26,0);
        for(auto x: text){
            v[x-'a']++;
        }
        // a,b,l,o,n
        return min({v['a'-'a'],v['b'-'a'],v['l'-'a']/2,v['o'-'a']/2,v['n'-'a']});
    }
};