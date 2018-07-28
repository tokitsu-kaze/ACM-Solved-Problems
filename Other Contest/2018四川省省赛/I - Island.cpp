#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int MAX=2e5+10;
const int mod=1e9+7;
vector<int> mp[MAX];
ll v[MAX],s,dp[MAX],sum[MAX],ans;
void dfs(int x,int fa)
{
    sum[x]=v[x];
    dp[x]=-1;
    for(auto to:mp[x])
    {
        if(to==fa) continue;
        dfs(to,x);
        dp[x]=max(dp[x],sum[to]);
        sum[x]+=sum[to];
    }
    dp[x]=max(dp[x],s-sum[x]);
    ans=min(ans,dp[x]);
} 
int main()
{
    int t,n,i,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&v[i]);
            mp[i].clear();
            s+=v[i];
        }
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            mp[a].pb(b);
            mp[b].pb(a);
        }
        ans=LLINF;
        dfs(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}