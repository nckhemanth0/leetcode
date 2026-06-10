class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long pos=-1;
        long long n=balance.size();
        for(long long i=0;i<n;i++){
            if(balance[i]<0){
                pos=i;
            }
        }
        if(pos==-1){
            return 0;
        }
        long long len=0,left=(pos-1+n)%n,right=(pos+1)%n,req=-1*balance[pos],ans=0;
        long long lp=0,rp=0;
        while(len<n/2){
            if(balance[left]<=req){
                ans+=(balance[left])*(1+lp);
                req-=balance[left];
            }else{
                ans+=((req)*(1+lp));
                req=0;
                break;
            }
            if(req==0){
                break;
            }
            if(left!=right){
                if(balance[right]<=req){
                    ans+=(balance[right])*(1+rp);
                    req-=balance[right];
                }else{
                    ans+=((req)*(1+rp));
                    req=0;
                    break;
                }
            }
            if(req==0){
                break;
            }
            len++;
            left--;
            left=(left+n)%n;
            right++;
            right=(right+n)%n;
            lp++;
            rp++;
        }
        if(req==0){
            return ans;
        }else{
            return -1;
        }
    }
};