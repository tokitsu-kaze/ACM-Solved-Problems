#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
    ll to,w,ci;
    node(){}
    node(ll a,ll b,ll c)
    {
        to=a;
        w=b;
        ci=c;
    }
};
ll path[2*MAX],deep[2*MAX],first[MAX],dis[MAX][2],flag[MAX],tot;
ll dp[2*MAX][24];
ll ci[MAX],v[MAX];
vector<node> mp[MAX];
ll deepmark[MAX];
void dfs(ll x,ll h)
{
    ll i;
    flag[x]=1;
    path[++tot]=x;
    first[x]=tot;
    deep[tot]=h;
    deepmark[x]=h;
    for(i=0;i<mp[x].size();i++)
    {
        ll to=mp[x][i].to;
        ll c=mp[x][i].ci;
        if(!flag[to])
        {
            dis[to][c&1]=dis[x][c&1]+mp[x][i].w;
            dis[to][(c&1)^1]=dis[x][(c&1)^1];
            dfs(to,h+1);
            path[++tot]=x;
            deep[tot]=h;
        }
    }
}
void ST(ll n)
{
    ll i,j,x,y;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i+(1<<j)-1<=n;i++)
        {
            x=dp[i][j-1];
            y=dp[i+(1<<(j-1))][j-1];
            dp[i][j]=deep[x]<deep[y]?x:y;
        }
    }
}
ll query(ll l,ll r)
{
    ll len,x,y;
    len=(ll)log2(r-l+1);
    x=dp[l][len];
    y=dp[r-(1<<len)+1][len];
    return deep[x]<deep[y]?x:y;
}
ll LCA(ll x,ll y)
{
    ll l,r,pos;
    l=first[x];
    r=first[y];
    if(l>r) swap(l,r);
    pos=query(l,r);
    return path[pos];
}
ll odd;
int main()
{
    ll n,i,a,b,q;
    ll ans,now;
    while(~scanf("%lld",&n))
    {
        for(i=1;i<=n;i++)
        {
            mp[i].clear();
            dis[i][0]=dis[i][1]=0;
            flag[i]=0;
        }
        ans=0;
        odd=0;
        for(i=0;i<n-1;i++)
        {
            scanf("%lld%lld%lld%lld",&a,&b,&v[i],&ci[i]);
            ans+=ci[i]*v[i]%mod;
            ans%=mod;
            if(ci[i]&1) odd=(odd+v[i])%mod;
            mp[a].pb(node(b,v[i],ci[i]));
            mp[b].pb(node(a,v[i],ci[i]));
        }
        tot=0;
        dfs(1,0);
        ST(2*n-1);
        scanf("%lld",&q);
        now=ans;
        while(q--)
        {
            scanf("%lld%lld",&a,&b);
            //加上路径上偶的
            //加上非路径上奇的=odd-路径上奇的
            ans=0;
            ans+=dis[a][0]+dis[b][0]-2*dis[LCA(a,b)][0];
            ans%=mod;
            ans+=odd-(dis[a][1]+dis[b][1]-2*dis[LCA(a,b)][1]%mod+mod)%mod+mod;
            ans%=mod;
            ans=(ans+now)%mod;
            assert(ans>=0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}