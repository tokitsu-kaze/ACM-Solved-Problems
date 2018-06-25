////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-30 00:12:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5692
////Problem Title: 
////Run result: Accept
////Run time:2137MS
////Run memory:30912KB
//////////////////System Comment End//////////////////
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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	ll l,r,mid,sum,tag;
	node(){}
	node(ll a,ll b)
	{
		l=a;
		r=b;
		sum=0;
		tag=0;
		mid=(l+r)>>1;
	}
}tree[4*MAX];
ll a[MAX];
void build(ll l,ll r,ll id)
{
	ll mid;
	tree[id]=node(l,r);
	if(l==r)
	{ 
		tree[id].sum=a[l];
		return;
	}
	mid=tree[id].mid;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tree[id].sum=max(tree[id<<1].sum,tree[id<<1|1].sum);
}
void pushdown(ll id)
{
	tree[id<<1].tag+=tree[id].tag;
	tree[id<<1|1].tag+=tree[id].tag;
	tree[id<<1].sum+=tree[id].tag;
	tree[id<<1|1].sum+=tree[id].tag;
	tree[id].tag=0;
}
void update(ll l,ll r,ll id,ll v)
{
	ll mid;
	if(l<=tree[id].l&&r>=tree[id].r)
	{
		tree[id].sum+=v;
		tree[id].tag+=v;
		return;
	}
	if(tree[id].tag) pushdown(id);
	mid=tree[id].mid;
	if(r<=mid) update(l,r,id<<1,v);
	else if(l>=mid+1) update(l,r,id<<1|1,v);
	else
	{
		update(l,mid,id<<1,v);
		update(mid+1,r,id<<1|1,v);
	}
	tree[id].sum=max(tree[id<<1].sum,tree[id<<1|1].sum);
}
ll query(ll l,ll r,ll id)
{
	ll mid;
	if(l==tree[id].l&&r==tree[id].r)
	{
		return tree[id].sum;
	}
	if(tree[id].tag) pushdown(id);
	mid=tree[id].mid;
	if(r<=mid) return query(l,r,id<<1);
	else if(l>=mid+1) return query(l,r,id<<1|1);
	else return max(query(l,mid,id<<1),query(mid+1,r,id<<1|1));
}
vector<ll> mp[MAX];
ll v[MAX],tot,l[MAX],r[MAX],dis[MAX];
void dfs(ll x,ll pre)
{
	ll i,to;
	if(pre!=-1) dis[x]+=dis[pre];
	dis[x]+=v[x];
	tot++;
	l[x]=tot;
	a[tot]=dis[x];
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int main()
{
	ll t,n,m,i,c,d,op,x,y,cas=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&c,&d);
			c++;
			d++;
			mp[c].pb(d);
			mp[d].pb(c);
		}
		for(i=1;i<=n;i++) scanf("%lld",&v[i]);
		tot=0;
		mem(dis,0);
		dfs(1,0);
		build(1,n,1);
		printf("Case #%lld:\n",cas++);
		while(m--)
		{
			scanf("%lld",&op);
			if(op==0)
			{
				scanf("%lld%lld",&x,&y);
				x++;
				update(l[x],r[x],1,y-v[x]);
				v[x]=y;
			}
			else if(op==1)
			{
				scanf("%lld",&x);
				x++;
				printf("%lld\n",query(l[x],r[x],1));
			}
		}
	}
	return 0;
} 