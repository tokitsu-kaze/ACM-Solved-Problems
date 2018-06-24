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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
ll a[MAX],bit[MAX];
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	ll a[MAX],tag[MAX<<2],maxx[MAX<<2],qv;
	void pushup(int id)
	{
		maxx[id]=max(maxx[ls],maxx[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		maxx[ls]+=tag[id];
		maxx[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		maxx[id]=0;
		if(l==r)
		{
			maxx[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			tag[id]+=qv;
			maxx[id]+=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	int query(int l,int r,int id)
	{
		int res=-1;
		if(maxx[id]<0) return -1;
		if(l==r)
		{
			if(maxx[id]==0) return l;
			return -1;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) res=query(l,mid,ls);
		if(res!=-1) return res;
		if(qr>mid) res=query(mid+1,r,rs);
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
}tr;
int main()
{
	int n,i,q;
	ll x;
	while(~scanf("%d%d",&n,&q))
	{
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			bit[i]=bit[i-1]+a[i];
			tr.a[i]=a[i]-bit[i-1];
		}
		tr.build(n);
		while(q--)
		{
			scanf("%d%lld",&tr.ql,&x);
			tr.qv=x-a[tr.ql];
			a[tr.ql]=x;
			tr.qr=tr.ql;
			tr.update(1,n,1);
			tr.qv*=-1;
			tr.ql++;
			tr.qr=n;
			if(tr.ql<=n) tr.update(1,n,1);
			tr.ql=1;
			printf("%d\n",tr.query(1,n,1));
		}
	}
	return 0;
}
