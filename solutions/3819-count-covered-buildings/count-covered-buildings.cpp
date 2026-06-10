struct MinMax {
    int lo = INT_MAX;
    int hi = INT_MIN;
};

class Solution {
public:
    int countCoveredBuildings___initial(int n, vector<vector<int>>& c) {
        unordered_map<int,set<int>> x,y;
        for(int i=0;i<c.size();i++){
            x[c[i][0]].insert(c[i][1]);
            y[c[i][1]].insert(c[i][0]);
        }
        int ans=0;
        for(int i=0;i<c.size();i++){
            int cnt=0;
            // check x
            cout<<c[i][0]<<endl;
            set<int> &ys=x[c[i][0]];
            if(c[i][1]>*ys.begin() && c[i][1]<*ys.rbegin()){
                cnt++;
            }
            set<int> &xs=y[c[i][1]];
            if(c[i][0]>*xs.begin() && c[i][0]<*xs.rbegin()){
                cnt++;
            }
            ans+=(cnt==2);
        }
        return ans;
    }

    

    int countCoveredBuildings(int n, vector<vector<int>>& c) {
        unordered_map<int, MinMax> x,y;
        for (auto &p : c) {
            int xi = p[0];
            int yi = p[1];
            auto &mmY = x[xi];
            mmY.lo = min(mmY.lo, yi);
            mmY.hi = max(mmY.hi, yi);
            auto &mmX = y[yi];
            mmX.lo = min(mmX.lo, xi);
            mmX.hi = max(mmX.hi, xi);
        }
        int ans = 0;
        for (auto &p : c) {
            int xi = p[0];
            int yi = p[1];
            int cnt = 0;
            const auto &ys = x[xi];
            if (yi > ys.lo && yi < ys.hi) cnt++;
            const auto &xs = y[yi];
            if (xi > xs.lo && xi < xs.hi) cnt++;
            ans += (cnt == 2);
        }
        return ans;
    }
    
};