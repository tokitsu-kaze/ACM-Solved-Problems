class Solution {
public:
    int dp[1005][1005];
    int longestPalindromeSubseq(string s) {
        int l,r,len,i,n;
        n=s.size();
        memset(dp,0,sizeof dp);
        for(i=0;i<n;i++) dp[i][i]=1;
        for(len=2;len<=n;len++)
        {
            for(l=0;l+len-1<n;l++)
            {
                r=l+len-1;
                if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1]+2;
                else dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
};
