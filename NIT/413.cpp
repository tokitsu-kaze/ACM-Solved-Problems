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
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	ll a[MAX],v[MAX<<2],tag[MAX<<2],maxx[MAX<<2],minn[MAX<<2];
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
		maxx[id]=max(maxx[ls],maxx[rs]);
		minn[id]=min(minn[ls],minn[rs]);
	}
	void pushdown(int id,int l,int r)
	{
		int mid=(l+r)>>1;
		if(!tag[id]) return;
		tag[ls]=tag[id];
		tag[rs]=tag[id];
		v[ls]=1LL*tag[id]*(mid-l+1);
		v[rs]=1LL*tag[id]*(r-mid);
		maxx[ls]=maxx[rs]=minn[ls]=minn[rs]=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		maxx[id]=-INF;
		minn[id]=INF;
		if(l==r)
		{
			v[id]=a[l];
			maxx[id]=minn[id]=a[l];
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
			tag[id]=qv;
			minn[id]=maxx[id]=qv;
			v[id]=1LL*qv*(r-l+1);
			return ;
		}
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	int query1(int l,int r,int id)
	{
		int res=0;
		if(minn[id]>qv) return 0;
		if(maxx[id]<qv) return 0;
		if(l>=ql&&r<=qr)
		{
			if(maxx[id]==minn[id])
			{
				if(maxx[id]==qv) return r-l+1;
				else return 0;
			}
		}
		if(l==r) return 0;
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) res+=query1(l,mid,ls);
		if(qr>mid) res+=query1(mid+1,r,rs);
		return res;
	}
	ll query2(int l,int r,int id)
	{
		ll res=0;
		if(l>=ql&&r<=qr) return v[id];
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) res+=query2(l,mid,ls);
		if(qr>mid) res+=query2(mid+1,r,rs);
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
	
}tr;
int main()
{
	int n,q,i,x;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&tr.a[i]);
		}
		tr.build(n);
		while(q--)
		{
			scanf("%d%d%d",&tr.ql,&tr.qr,&tr.qv);
			printf("%d %lld\n",tr.query1(1,n,1),tr.query2(1,n,1));
			tr.update(1,n,1);
		}
	}
	return 0;
}