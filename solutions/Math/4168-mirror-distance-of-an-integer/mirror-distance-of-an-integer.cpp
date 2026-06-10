class Solution {
public:
    int mirrorDistance(int n) {
        string x=to_string(n);
        reverse(x.begin(),x.end());
        int y=stoi(x);
        return abs(n-y);
    }
};