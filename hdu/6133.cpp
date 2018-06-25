////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-03-14 21:37:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6133
////Problem Title: 
////Run result: Accept
////Run time:967MS
////Run memory:28216KB
//////////////////System Comment End//////////////////
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
const int MAX=1e5+10;
const ll mod=1e9+7;
ll ans[MAX*18],res[MAX];
vector<int> mp[MAX],Hash;
int vv[MAX];
struct Segment_Tree
{
	int s[MAX*18],top;//ÄÚ´æ³Ø 
	int root[MAX],tot,ls[MAX*18],rs[MAX*18],sz[MAX*18],ql,qr,qv,n;
	ll v[MAX*18];
	void init()
	{
		top=0;
		mem(root,0);
		ls[0]=rs[0]=0;
		sz[0]=ans[0]=v[0]=0;
		tot=1;
	}
	int newnode()
	{
		int t;
		if(top) t=s[--top];
		else t=tot++;
		sz[t]=ls[t]=rs[t]=0;
		ans[t]=v[t]=0;
		return t;
	}
	void delnode(int x)
	{
		s[top++]=x;
	}
	void pushup(int id)
	{
		v[id]=v[ls[id]]+v[rs[id]];
		sz[id]=sz[ls[id]]+sz[rs[id]];
	}
	void insert(int l,int r,int &id,int pos)
	{
		int mid;
		if(!id) id=newnode();
		if(l==r)
		{
			sz[id]++;
			ans[id]=v[id]=1LL*sz[id]*qv;
			return;
		}
		mid=(l+r)>>1;
		if(pos<=mid) insert(l,mid,ls[id],pos);
		else insert(mid+1,r,rs[id],pos);
		pushup(id);
		ans[id]=ans[ls[id]]+ans[rs[id]];
	}
	int merge(int a,int b)
	{
		if(!a||!b) return a+b;
		ls[a]=merge(ls[a],ls[b]);
		rs[a]=merge(rs[a],rs[b]);
		if(!ls[a]&&!rs[a])
		{
			v[a]+=v[b];
			sz[a]+=sz[b];
			ans[a]=(v[a]/sz[a]+v[a])*sz[a]/2;
		}
		else
		{
			pushup(a);
			ans[a]=ans[ls[a]]+ans[rs[a]]+sz[rs[a]]*v[ls[a]];
		}
		delnode(b);
		return a;
	}
	void dfs(int x,int fa)
	{
		int i,to;
		qv=vv[x];
		insert(1,sz(Hash),root[x],lower_bound(all(Hash),vv[x])-Hash.begin()+1);
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(to==fa) continue;
			dfs(to,x);
			root[x]=merge(root[x],root[to]);
		}
		res[x]=ans[root[x]];
	}
}tree;
int main()
{
	int t,n,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tree.init();
		Hash.clear();
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			scanf("%d",&vv[i]);
			Hash.pb(vv[i]);
			ans[i]=0;
		}
		sort(all(Hash));
		Hash.resize(unique(all(Hash))-Hash.begin());
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		tree.dfs(1,-1);
		for(i=1;i<=n;i++) printf("%lld ",res[i]);
		puts("");
	}
	return 0;
}