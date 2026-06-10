class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> cur_set;
        int n=arr.size();
        unordered_set<int> ans;
        for(int i=0;i<n;i++){
            unordered_set<int> cur_set2;
            for(auto x: cur_set){
                cur_set2.insert(x|arr[i]);
            }
            cur_set2.insert(arr[i]);
            ans.insert(cur_set2.begin(),cur_set2.end());
            cur_set=move(cur_set2);
        }
        return ans.size();
    }
};