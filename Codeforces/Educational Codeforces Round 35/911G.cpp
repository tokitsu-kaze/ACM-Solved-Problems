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
const double eps=1e-8;
const int MAX=4e5+10;
const ll mod=1e9+7;
struct Segment_Tree
{
	int s[MAX*20],top;
	int root[105],tot,ls[MAX*20],rs[MAX*20],ql,qr,qv,n;
	void init()
	{
		top=0;
		mem(root,0);
		ls[0]=rs[0]=0;
		tot=1;
	}
	int newnode()
	{
		int t;
		if(top) t=s[--top];
		else t=tot++;
		ls[t]=rs[t]=0;
		return t;
	}
	void delnode(int x)
	{
		s[top++]=x;
	}
	void insert(int l,int r,int &id,int pos)
	{
		int mid;
		if(!id) id=newnode();
		if(l==r) return;
		mid=(l+r)>>1;
		if(pos<=mid) insert(l,mid,ls[id],pos);
		else insert(mid+1,r,rs[id],pos);
	}
	void build(int _n)
	{
		int x,i;
		n=_n;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			insert(1,n,root[x],i);
		}
	}
	int merge(int a,int b)
	{
		if(!a||!b) return a+b;
		ls[a]=merge(ls[a],ls[b]);
		rs[a]=merge(rs[a],rs[b]);
		delnode(b);
		return a;
	}
	int split(int l,int r,int &id)
	{
		int mid,t;
		if(!id) return 0;
		if(ql<=l&&r<=qr)
		{
			int temp=id;
			id=0;
			return temp;
		}
		t=newnode();
		mid=(l+r)>>1;
		if(ql<=mid) ls[t]=split(l,mid,ls[id]);
		if(qr>mid) rs[t]=split(mid+1,r,rs[id]);
		return t;
	}
	void work()
	{
		int q,x,y;	
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&ql,&qr,&x,&y);
			if(x!=y) root[y]=merge(root[y],split(1,n,root[x]));
		}
	}
	int ans[MAX];
	void dfs(int l,int r,int id)
	{
		int mid;
		if(!id) return;
		if(l==r)
		{
			ans[l]=qv;
			return;
		}
		mid=(l+r)>>1;
		dfs(l,mid,ls[id]);
		dfs(mid+1,r,rs[id]);
	}
	void solve()
	{
		int i;
		for(i=1;i<=100;i++) qv=i,dfs(1,n,root[i]);
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	
}tree;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		tree.init();
		tree.build(n);
		tree.work();
		tree.solve();
	}
	return 0;
}