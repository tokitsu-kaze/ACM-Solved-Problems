#include<bits/stdc++.h>
using namespace std;
long long dp[2297151],a[55],b[55],lim[55];
int n,ki,tmp,maxbit;
bool inq[2297151];
int cntbit(int x)
{
    int ans=0;
    while(x)
    {
        x-=(x&-x);
        ++ans;
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        maxbit=(1<<n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld %lld %d",&a[i],&b[i],&ki);
            lim[i]=0;
            for(int j=1;j<=ki;++j)
            {
                scanf("%d",&tmp);
                lim[i]|=(1<<(tmp-1));
            }
        }
        for(int i=0;i<maxbit;++i)
        {
            dp[i]=-(1LL<<60);
            inq[i]=false;
        }
        dp[0]=0;
        queue<int>q;
        q.push(0);
        inq[0]=true;
        while(!q.empty())
        {

            int now=q.front();
            q.pop();
            for(int j=0;j<n;++j)
            {
                if((now&(1<<j))==0&&((now&lim[j+1])==lim[j+1]))
                {
                    int nex=now|(1<<j);
                    dp[nex]=max(dp[nex],dp[now]+(cntbit(now)+1)*a[j+1]+b[j+1]);
                    if(!inq[nex])
                    {
                        q.push(nex);
                        inq[nex]=true;
                    }
                }
            }
        }
        long long ans=dp[0];
        for(int i=1;i<maxbit;++i)
        {
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}