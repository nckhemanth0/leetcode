class Solution {
public:

    int intersectionSizeTwo__1(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int> &v1, const vector<int> &v2){
            return v1[1]<v2[1];
        });
        int p1=intervals[0][1]-1,p2=intervals[0][1];
        int ans=2;
        int cnt=0;
        for(int i=1;i<n;i++){
            // cout<<"prev's: "<<p1<<" "<<p2<<endl;
            int l=intervals[i][0], r=intervals[i][1];
            // cout<<l<<" "<<r<<endl;
            cnt=0;
            if(p1>=l && p1<=r){
                cnt++;
            }
            if(p2>=l && p2<=r){
                cnt++;
            }
            if(cnt==0){
                p1=intervals[i][1]-1,p2=intervals[i][1];
            }else if(cnt==1){
                p1=p2;
                if(p2==intervals[i][1]){
                    p1=intervals[i][1]-1;
                }
                p2=intervals[i][1];
            }
            // cout<<cnt<<endl;
            ans+=(2-cnt);
        }
        return ans;
    }
    
    //  ========= ============ ============

    int intersectionSizeTwo__2(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1] < b[1];
        });
        vector<int>prev = {intervals[0][1]-1, intervals[0][1]};
        for(int i=1; i<intervals.size(); ++i){
            if(prev[prev.size()-2]>=intervals[i][0]){
                continue;
            }
            else if(prev[prev.size()-1]>=intervals[i][0]){
                if(prev[prev.size()-1]==intervals[i][1]){
                    prev[prev.size()-1]=intervals[i][1]-1;
                }
                prev.push_back(intervals[i][1]);
            }
            else{
                prev.push_back(intervals[i][1]-1);
                prev.push_back(intervals[i][1]);
            }
        }
        return prev.size();
    }

    // ====== ======= ========

    int intersectionSizeTwo__3(vector<vector<int>>& intervals) {
        // Sort intervals by end point, then by start descending
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1] < b[1];
        });
        
        int count = 0;
        int first = -1;  // Second largest number in solution
        int second = -1; // Largest number in solution
        
        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            if (start > second) {
                // No overlap with current solution - need 2 new numbers
                // Add the two largest numbers from this interval
                first = end - 1;
                second = end;
                count += 2;
            } else if (start > first) {
                // Overlaps with only one number - need one more
                // Add the largest number from this interval
                // first = second;
                // second = end;

                first=second;
                if(second==end){
                    first=end-1;
                }
                second=end;
                count += 1;
            }
            // else: overlaps with at least two numbers - do nothing
        }
        
        return count;
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int>&b){
            if(a[1]==b[1]){
                return a[0]>b[0];
            }
            return a[1]<b[1];
        });

        int count = 0;

        int p1=-1;
        int p2=-1;

        for(auto interval:intervals){
            int start = interval[0];
            int end = interval[1];

            if(start<=p2){
                continue;
            }

            if(start<=p1){
                count++;
                p2=p1;
                p1=end;
            }
            else{
                count+=2;
                p1=end;
                p2=end-1;
            }
        }

        return count;
    }

    // ===== ======= ==== ==== === 

    /*

                    \U0001f6e0 Variations
                        Generalized for k elements:
                        public int intersectionSizeK(int[][] intervals, int k) {
                            Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
                            List<Integer> result = new ArrayList<>();
                            
                            for (int[] interval : intervals) {
                                int start = interval[0], end = interval[1];
                                int count = 0;
                                
                                // Count how many of our result are in this interval
                                for (int num : result) {
                                    if (num >= start && num <= end) count++;
                                }
                                
                                // Add missing numbers from the end
                                for (int i = 0; i < k - count; i++) {
                                    result.add(end - i);
                                }
                            }
                            
                            return result.size();
                        }

    */

    
};