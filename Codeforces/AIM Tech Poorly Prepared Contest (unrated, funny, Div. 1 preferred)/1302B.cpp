#include<bits/stdc++.h>
using namespace std;
const int MAXN=50005;
vector<int>G[MAXN];
int u,v,n,m,temp[MAXN],mid,l,r;
bool vis[MAXN];
bitset<MAXN/5> dp[MAXN];
bitset<MAXN/5> ONE;
bitset<MAXN/5> dfs(int x)
{
    if(vis[x])return dp[x];
    vis[x]=true;
    if(l<=x&&x<=r)dp[x]=ONE<<(x-l);
    else dp[x]=0;
    for(auto &i:G[x])
    {
        dp[x]|=dfs(i);
    }
    return dp[x];
}
int main()
{
    ONE=1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d %d",&u,&v);
        G[v].push_back(u);
    }
    long long ans=0;
    mid=n/2;
    for(int i=1;i<=n;++i)
    {
        l=1;
        r=10000;
        temp[i]=dfs(i).count();
    }
    for(int i=1;i<=n;++i)
    {
        vis[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        l=10001;
        r=20000;
        temp[i]+=dfs(i).count();
    }
    for(int i=1;i<=n;++i)
    {
        vis[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        l=20001;
        r=30000;
        temp[i]+=dfs(i).count();
    }
    for(int i=1;i<=n;++i)
    {
        vis[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        l=30001;
        r=40000;
        temp[i]+=dfs(i).count();
    }
    for(int i=1;i<=n;++i)
    {
        vis[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        l=40001;
        r=50000;
        temp[i]+=dfs(i).count();
        ans+=1LL*temp[i]*temp[i];
    }
    printf("%lld\n",ans);
    return 0;
}

