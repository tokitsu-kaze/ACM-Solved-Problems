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
const double eps=1e-8;
const int MAX=3e5+10;
const int mod=1e9+7;
struct node
{
	ll id,v,tid,cost;
	node(){}
	node(ll a,ll b,ll c,ll d) :id(a),v(b),tid(c),cost(d){}
	friend bool operator <(node a,node b)
	{
		if(a.v==b.v) return a.cost>b.cost;
		return a.v>b.v;
	}
};
vector<node> mp[MAX];
int flag[MAX];
ll dis[MAX];
vector<ll> res;
ll dij(int s)
{
	int i,sz;
	ll ans=0;
	priority_queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(flag,0);
	res.clear();
	dis[s]=0;
	q.push(node(s,0,0,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		ans+=t.cost;
		if(t.tid) res.pb(t.tid);
		sz=sz(mp[t.id]);
		for(i=0;i<sz;i++)
		{
			to=mp[t.id][i];
			if(dis[to.id]>=dis[t.id]+to.v)
			{
				dis[to.id]=dis[t.id]+to.v;
				q.push(node(to.id,dis[to.id],to.tid,to.v));
			}
		}
	}
	return ans;
} 
int main()
{
	int n,m,s;
	ll a,b,w,i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&w);
			mp[a].pb(node(b,w,i,0));
			mp[b].pb(node(a,w,i,0));
		}
		scanf("%d",&s);
		printf("%lld\n",dij(s));
		sort(all(res));
		for(i=0;i<sz(res);i++) printf("%lld%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}