#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int v[MAX],tot,l[MAX],r[MAX],a[MAX];
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
void build(int l,int r,int id)
{
	int mid;
	tree[id]=node(l,r);
	if(l==r)
	{ 
		tree[id].sum=a[l];
		return;
	}
	mid=tree[id].mid;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
}
void pushdown(int id)
{	
	tree[id<<1].tag^=1;
	tree[id<<1|1].tag^=1;
	tree[id<<1].sum=(tree[id<<1].r-tree[id<<1].l+1)-tree[id<<1].sum;
	tree[id<<1|1].sum=(tree[id<<1|1].r-tree[id<<1|1].l+1)-tree[id<<1|1].sum;
	tree[id].tag=0;
}
void update(int l,int r,int id)
{
	int mid;
	if(l<=tree[id].l&&r>=tree[id].r)
	{
		tree[id].sum=tree[id].r-tree[id].l+1-tree[id].sum;
		tree[id].tag^=1;
		return;
	}
	if(tree[id].tag) pushdown(id);
	mid=tree[id].mid;
	if(r<=mid) update(l,r,id<<1);
	else if(l>=mid+1) update(l,r,id<<1|1);
	else
	{
		update(l,mid,id<<1);
		update(mid+1,r,id<<1|1);
	}
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
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
void dfs(int x)
{
	int i;
	tot++;
	a[tot]=v[x];
	l[x]=tot;
	for(i=0;i<sz(mp[x]);i++)
	{
		dfs(mp[x][i]);
	}
	r[x]=tot;
}
int main()
{
	int n,i,x,q;
	char op[111];
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x].pb(i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		tot=0;
		dfs(1);
		build(1,n,1);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%s%d",op,&x);
			if(op[0]=='g') printf("%d\n",query(l[x],r[x],1));
			else update(l[x],r[x],1);
		}
	}
	return 0;
}