class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        const double PI = 3.14159265358979323846;
        if(!(a<b+c && b<c+a && c<a+b)){
            return {};
        }
        double A_rad=acos((b*b+ c*c - a*a) / (2 * b * c));
        double B_rad = acos((a*a + c*c - b*b) / (2 * a * c));
        double C_rad = acos((a*a + b*b - c*c) / (2 * a * b));
        double A_deg = A_rad * (180.0 / PI);
        double B_deg = B_rad * (180.0 / PI);
        double C_deg = C_rad * (180.0 / PI);
        vector<double> ans;
        ans.push_back(A_deg);
        ans.push_back(B_deg);
        ans.push_back(C_deg);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};