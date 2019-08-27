#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/***************************************  head  **********************************************/
struct node
{
	ll id,v;
	node(){}
	node(ll a,ll b) :id(a),v(b){}
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
vector<node> mp[2][MAX];
ll flag[MAX],dis[2][MAX];
void dij(ll s,ll f)
{
	ll i,sz;
	priority_queue<node> q;
	node t,to;
	mem(dis[f],0x3f);
	mem(flag,0);
	dis[f][s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		sz=sz(mp[f][t.id]);
		for(i=0;i<sz;i++)
		{
			to=mp[f][t.id][i];
			if(dis[f][to.id]>dis[f][t.id]+to.v)
			{
				dis[f][to.id]=dis[f][t.id]+to.v;
				q.push(node(to.id,dis[f][to.id]));
			}
		}
	}
} 
ll ans[MAX];
int main()
{
	ll n,m,s,t,a,b,i,v,w,cas=1;
	while(~scanf("%lld%lld",&n,&m))
	{
		assert(2<=n&&n<=100000);
		assert(1<=m&&m<=min(1LL*n*(n-1)/2,100000LL));
		for(i=1;i<=n;i++) mp[0][i].clear(),mp[1][i].clear();
		while(m--)
		{
			scanf("%lld%lld%lld%lld",&a,&b,&v,&w);
			assert(a>=1&&a<=n);
			assert(b>=1&&b<=n);
			assert(v>=1&&v<=1000000000);
			assert(w>=1&&w<=1000000000);
			mp[0][a].pb(node(b,v));
			mp[0][b].pb(node(a,v));
			mp[1][a].pb(node(b,w));
			mp[1][b].pb(node(a,w));
		}
		scanf("%lld%lld",&s,&t);
		assert(s>=1&&s<=n);
		assert(t>=1&&t<=n);
		dij(s,0);
		dij(t,1);
		ans[n+1]=LLINF;
		for(i=n;i;i--)
		{
			ans[i]=min(ans[i+1],dis[0][i]+dis[1][i]);
		}
		for(i=1;i<=n;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}

