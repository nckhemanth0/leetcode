class Solution {
public:

    int n1,n2,n3;
    int dp[101][101];
    bool rec(string &s1, string &s2, string &s3, int i, int j, int k){
        if(i==n1){
            return s2.substr(j)==s3.substr(k);
        }
        if(j==n2){
            return s1.substr(i)==s3.substr(k);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=false;
        if((s1[i]==s3[k] && rec(s1,s2,s3,i+1,j,k+1)) || (s2[j]==s3[k] && rec(s1,s2,s3,i,j+1,k+1))){
            ans=true;
        }
        return dp[i][j]=ans;

    }

    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size(), n2=s2.size(), n3=s3.size();
        if((n1+n2)!=n3){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return rec(s1,s2,s3,0,0,0);
    }

    // ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ====== ======


    int dp1[101][101][201][3];
    // prev: 1 - taken from s1, 2 mean taken from s2
    int rec(string s1, string s2, string s3, int i, int j, int k, int prev){
        // cout<<"============="<<endl;
        // cout<<"i: "<<i<<", j: "<<j<<", k: "<<k<<", prev: "<<prev<<endl;
        // for(auto x: v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // cout<<endl;
        // cout<<"============="<<endl;
        if(i==n1 && j==n2 && k==n3){
            return 1;
        }
        if(dp1[i][j][k][prev]!=-1){
            return dp1[i][j][k][prev];
        }
        int ans=0;
        // s1&s2
        if(prev!=1){
            for(int x=i;x<n1;x++){
                // [i to x] substring
                int len=x-i+1;
                if(k+len-1<n3 && s3[k]==s1[i] && s3.substr(k,len)==s1.substr(i,len)){
                    // v.push_back({1,s3.substr(k,len)});
                    ans|=rec(s1,s2,s3,x+1,j,k+len,1);
                    // v.pop_back();
                }else{
                    break;
                }
            }
        }
        // s2&s3
        if(prev!=2){
            for(int x=j;x<n2;x++){
                // [i to x] substring
                int len=x-j+1;
                if(k+len-1<n3 && s3[k]==s2[j] && s3.substr(k,len)==s2.substr(j,len)){
                    // v.push_back({1,s3.substr(k,len)});
                    ans|=rec(s1,s2,s3,i,x+1,k+len,2);
                    // v.pop_back();
                }else{
                    break;
                }
            }
        }

        return dp1[i][j][k][prev]=ans;
    }

    bool isInterleave__1(string s1, string s2, string s3) {
        n1=s1.size(), n2=s2.size(), n3=s3.size();
        if((n1+n2)!=n3){
            return false;
        }
        memset(dp1,-1,sizeof(dp1));
        return rec(s1,s2,s3,0,0,0,0);
    }
};