class Solution {
public:
    int countOdds(int low, int high) {
        int ans=(high-low)/2;
        if(low&1 || high&1){
            ans++;
        }
        return ans;
    }
};

/*
        class Solution:
        def countOdds(self, low: int, high: int) -> int:
            def count(n):
                return math.ceil(n / 2)

            return count(high) - count(low - 1)
*/