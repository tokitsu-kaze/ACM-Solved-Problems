class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // (x+x+y-1)*y/2
        int ans=0;
        int i,j,sq,tmp;
        sq=sqrt(2*n+0.5);
        for(i=1;i<=sq;i++)
        {
            if(2*n%i) continue;
            tmp=2*n/i+1-i;
            if(tmp%2==0) ans++;
        }
        return ans;
    }
};
