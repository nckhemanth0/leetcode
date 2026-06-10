class Solution {
public:

    int reverse(int z){
        int rev=0;
        while(z){
            rev|=(z&1);
            z=z>>1;
            rev=rev<<1;
        }
        return rev;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int x, int y){
            int revx=reverse(x), revy=reverse(y);
            if(revx==revy){
                return x<=y;
            }
            return revx<=revy;
        });
        return nums;
    }
};