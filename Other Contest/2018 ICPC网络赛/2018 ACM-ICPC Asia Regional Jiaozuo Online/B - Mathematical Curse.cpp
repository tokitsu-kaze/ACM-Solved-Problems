#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const long long INF=((1LL<<60)+7);
long long dp[MAXN][10][2],a[MAXN],beg;
int T,n,m;
char f[15];
long long get_ans(long long a,char ff,long long b)
{
    if(ff=='+')return a+b;
    if(ff=='-')return a-b;
    if(ff=='*')return a*b;
    if(ff=='/')return a/b;
}

int main()
{
    /*freopen("1.txt", "r", stdin);
    freopen("lalala.txt", "w", stdout);*/
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %lld",&n,&m,&beg);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<=n+1;++i)
        {
            for(int j=0;j<=m+1;++j)
            {
                dp[i][j][0]=dp[i][j][1]=INF;
            }
        }
        scanf("%s",f+1);
        dp[0][0][0]=dp[0][0][1]=beg;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=min(m,i);++j)
            {
                if(dp[i-1][j][0]!=INF)
                dp[i][j][0]=dp[i-1][j][0];
                if(dp[i-1][j][1]!=INF)
                dp[i][j][1]=dp[i-1][j][1];
                if(j)
                {
                    if(dp[i][j][0]==INF||dp[i][j][0]<get_ans(dp[i-1][j-1][0],f[j],a[i]))
                    dp[i][j][0]=get_ans(dp[i-1][j-1][0],f[j],a[i]);
                    dp[i][j][0]=max(dp[i][j][0],get_ans(dp[i-1][j-1][1],f[j],a[i]));
                    if(dp[i][j][1]==INF||dp[i][j][1]>get_ans(dp[i-1][j-1][0],f[j],a[i]))
                    dp[i][j][1]=get_ans(dp[i-1][j-1][0],f[j],a[i]);
                    dp[i][j][1]=min(dp[i][j][1],get_ans(dp[i-1][j-1][1],f[j],a[i]));
                }
            }
        }
        printf("%lld\n",dp[n][m][0]);
    }
    return 0;
}