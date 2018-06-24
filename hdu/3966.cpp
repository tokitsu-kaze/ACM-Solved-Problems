////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-30 16:20:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3966
////Problem Title: 
////Run result: Accept
////Run time:1778MS
////Run memory:13936KB
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
const int MAX=5e4+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int deep[MAX],fa[MAX],size[MAX],son[MAX];
int rnk[MAX],top[MAX],tid[MAX],tot;
void init()
{
	mem(son,-1);
	tot=0;
}
void dfs1(int x,int pre,int h)  
{
	int i,to;
	deep[x]=h;
	fa[x]=pre;
	size[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs1(to,x,h+1);
		size[x]+=size[to];
		if(son[x]==-1||size[to]>size[son[x]]) son[x]=to;
	}
}
void dfs2(int x,int tp)
{
	int i,to;
	top[x]=tp;
	tid[x]=++tot;
	rnk[tid[x]]=x;
	if(son[x]==-1) return;
	dfs2(son[x],tp);
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
	}
}
struct node
{
	int l,r,mid,sum,tag;
	node(){}
	node(int a,int b)
	{
		l=a;
		r=b;
		sum=0;
		tag=0;
		mid=(l+r)>>1;
	}
}tree[4*MAX];
int v[MAX];
void build(int l,int r,int id)
{
	int mid;
	tree[id]=node(l,r);
	if(l==r)
	{ 
		tree[id].sum=v[rnk[l]];
		return;
	}
	mid=tree[id].mid;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
}
void pushdown(int id)
{
	tree[id<<1].tag+=tree[id].tag;
	tree[id<<1|1].tag+=tree[id].tag;
	tree[id<<1].sum+=tree[id].tag;
	tree[id<<1|1].sum+=tree[id].tag;
	tree[id].tag=0;
}
void update(int l,int r,int id,int v)
{
	int mid;
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
int query(int l,int r,int id)
{
	int mid;
	if(l==tree[id].l&&r==tree[id].r)
	{
		return tree[id].sum;
	}
	if(tree[id].tag) pushdown(id);
	mid=tree[id].mid;
	if(r<=mid) return query(l,r,id<<1);
	else if(l>=mid+1) return query(l,r,id<<1|1);
	else return query(l,mid,id<<1)+query(mid+1,r,id<<1|1);
}
void modify(int x,int y,int val)
{  
	while(top[x]!=top[y])
	{  
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(tid[top[x]],tid[x],1,val);
		x=fa[top[x]];
    }  
    if(deep[x]>deep[y]) swap(x,y);
    update(tid[x],tid[y],1,val);
}
int main()
{
	int n,m,q,i,x,y,w,a,b;
	char op[11];
	while(~scanf("%d%d%d",&n,&m,&q))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			scanf("%d",&v[i]);
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		init();
		dfs1(1,0,0);
		dfs2(1,1);
		build(1,n,1);
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='Q')
			{
				scanf("%d",&x);
				printf("%d\n",query(tid[x],tid[x],1));
			}
			else
			{
				scanf("%d%d%d",&x,&y,&w);
				if(op[0]=='D') w*=-1;
				modify(x,y,w);
			}
		}
	}
	return 0;
}