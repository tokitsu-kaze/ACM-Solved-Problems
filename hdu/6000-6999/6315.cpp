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
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int get(int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	int query(int l,int r)
	{
		return get(r)-get(l-1);
	}
}bit;
int b[MAX];
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	int mn[MAX<<2],tag[MAX<<2];
	void pushup(int id)
	{
		mn[id]=min(mn[ls],mn[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		mn[ls]+=tag[id];
		mn[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		mn[id]=INF;
		tag[id]=0;
		if(l==r)
		{
			mn[id]=b[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr&&mn[id]+qv)
		{
			mn[id]+=qv;
			tag[id]+=qv;
			return;
		}
		if(l==r&&mn[id]+qv==0)
		{
			mn[id]=b[l];
			bit.insert(l,1);
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,int v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
}tr;
int main()
{
	int n,q,i,l,r;
	char op[22];
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		tr.build(n);
		bit.init(n);
		while(q--)
		{
			scanf(" %s%d%d",op,&l,&r);
			if(op[0]=='a') tr.upd(l,r,-1);
			else printf("%d\n",bit.query(l,r));
		}
	}
	return 0;
}

