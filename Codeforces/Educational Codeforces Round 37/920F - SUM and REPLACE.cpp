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
const int MAX=3e5+10;
const ll mod=1e9+7;
int d[(int)1e6+10];
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	ll a[MAX],v[MAX<<2],mx[MAX<<2];
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
		mx[id]=max(mx[ls],mx[rs]);
	}
	void build(int l,int r,int id)
	{
		mx[id]=0;
		if(l==r)
		{
			scanf("%lld",&a[l]);
			mx[id]=v[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(mx[id]<=2) return;
		if(l==r)
		{
			mx[id]=v[id]=d[v[id]];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	ll query(int l,int r,int id)
	{
		ll res=0;
		if(l>=ql&&r<=qr) return v[id];
		int mid=(l+r)>>1;
		if(ql<=mid) res+=query(l,mid,ls);
		if(qr>mid) res+=query(mid+1,r,rs);
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
	
}tree;
void init(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			d[j]++;
		}
	}
}
int main()
{
	int n,m,i,op;
	init((int)1e6);
	while(~scanf("%d%d",&n,&m))
	{
		tree.build(n);
		while(m--)
		{
			scanf("%d%d%d",&op,&tree.ql,&tree.qr);
			if(op==1) tree.update(1,n,1);
			else printf("%lld\n",tree.query(1,n,1));
		}
	}
	return 0;
}