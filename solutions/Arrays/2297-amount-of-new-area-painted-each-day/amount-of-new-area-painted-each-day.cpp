class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int,int> mp;
        vector<int> final_ans;
        for(auto p: paint){
            int l=p[0],r=p[1];
            int ans=r-l;
            auto it=mp.upper_bound(l);
            if(it!=mp.begin() && prev(it)->second>l){
                it--;
            }
            while(it!=mp.end() && r>it->first){
                int ol_l=max(l,it->first);
                int ol_r=min(r,it->second);
                if(ol_l<ol_r){
                    ans-=(ol_r-ol_l);
                }
                l=min(l,it->first);
                r=max(r,it->second);
                it=mp.erase(it);
            }
            mp[l]=r;
            final_ans.push_back(ans);
        }
        return final_ans;
    }
};