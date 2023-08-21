#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,l,r,T;
long long dp[1000005];
int main()
{
    scanf("%d",&T);
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<=1000000;++i)
    {
        dp[i]=(dp[i-1]+dp[i-3])%mod;
    }
    while(T--)
    {
        scanf("%d %d %d",&n,&l,&r);
        if(l!=1)
        {
            ++l;
        }
        if(r!=n)
        {
            --r;
        }
        printf("%lld\n",dp[r-l+1]);
    }

    return 0;
}

