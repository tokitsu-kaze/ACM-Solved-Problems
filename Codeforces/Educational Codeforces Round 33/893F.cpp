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
int v[MAX<<6],ls[MAX<<6],rs[MAX<<6],root[MAX],tot;
void init()
{
	mem(root,0);
	ls[0]=rs[0]=0;
	v[0]=INF; 
	tot=1;
}
int newnode()
{
	ls[tot]=rs[tot]=0;
	v[tot]=0;
	return tot++;
}
void Insert(int l,int r,int &id,int pos,int val)
{
	int mid;
	if(!id) id=newnode();
	if(l==r&&pos==l)
	{
		v[id]=val;
		return;
	}
	mid=(l+r)>>1;
	if(pos<=mid) Insert(l,mid,ls[id],pos,val);
	else if(pos>=mid+1) Insert(mid+1,r,rs[id],pos,val);
	v[id]=min(v[ls[id]],v[rs[id]]);
}
int merge(int a,int b)
{
    if(!a) return b;
    if(!b) return a;
    int id=newnode();
    ls[id]=merge(ls[a],ls[b]);
    rs[id]=merge(rs[a],rs[b]);
    if(ls[id]||rs[id]) v[id]=min(v[ls[id]],v[rs[id]]);
    else v[id]=min(v[a],v[b]);
    return id;
}
int query(int l,int r,int id,int x,int y)
{
	if(!id) return INF;
	if(l>=x&&r<=y) return v[id];
	int mid=(l+r)>>1;
	if(y<=mid) return query(l,mid,ls[id],x,y);
	else if(x>=mid+1) return query(mid+1,r,rs[id],x,y);
	else return min(query(l,mid,ls[id],x,y),query(mid+1,r,rs[id],x,y));
	v[id]=min(v[ls[id]],v[rs[id]]);
}
vector<int> mp[MAX];
int vv[MAX],deep[MAX];
void dfs(int x,int fa,int h)
{
	int i,to;
	deep[x]=h;
	Insert(1,MAX-10,root[x],deep[x],vv[x]);
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		dfs(to,x,h+1);
		root[x]=merge(root[to],root[x]);
	}
}
int main()
{
	int n,rt,q,i,a,b,ans,x,k;
	while(~scanf("%d%d",&n,&rt))
	{
		init();
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			scanf("%d",&vv[i]);
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		dfs(rt,-1,1);
		scanf("%d",&q);
		ans=0;
		while(q--)
		{
			scanf("%d%d",&a,&b);
			x=(a+ans)%n+1;
			k=(b+ans)%n;
			ans=query(1,MAX-10,root[x],deep[x],min(MAX-10,deep[x]+k));
			printf("%d\n",ans);
		}
	}
	return 0;
}