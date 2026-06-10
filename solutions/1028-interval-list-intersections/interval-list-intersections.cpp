class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n1=a.size();
        int n2=b.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n1 && j<n2){
            int start=max(a[i][0],b[j][0]), end=min(a[i][1],b[j][1]);
            int intersection=end-start;
            if(intersection>=0){
                ans.push_back({start,end});
            }
            if(a[i][1]>b[j][1]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }

    // vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    //     map<int,int> mp;
    //     for(auto x: firstList){
    //         mp[x[0]]++;
    //         mp[x[1]+1]--;
    //     }
    //     for(auto x: secondList){
    //         mp[x[0]]++;
    //         mp[x[1]+1]--;
    //     }
    //     int cnt=0,start,end,previous;
    //     vector<vector<int>> ans;
    //     for(auto it=mp.begin();it!=mp.end();it++){
    //         previous=cnt;
    //         cnt+=it->second;
    //         cout<<it->first<<" "<<cnt<<endl;
    //         if(cnt==2 && previous==1){
    //             start=it->first;
    //         }else if(cnt==1 && previous==2){
    //             end=it->first-1;
    //             ans.push_back({start,end});
    //         }else if(cnt==2 && previous==2){
    //             end=it->first;
    //             ans.push_back({end,end});
    //         }
    //     }
    //     return ans;
    // }
};