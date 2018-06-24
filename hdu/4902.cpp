////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-05 21:08:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4902
////Problem Title: 
////Run result: Accept
////Run time:1154MS
////Run memory:8740KB
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
template<int MAXN,typename T> struct segment_tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	vector<T> a,v,tag;
	segment_tree(int _n):n(_n)
	{
		a.resize(MAXN);
		v.resize(MAXN<<2);
		tag.resize(MAXN<<2);
	}
	void pushup(int id)
	{
		v[id]=max(v[ls],v[rs]);
		if(tag[ls]==tag[rs]&&tag[ls]!=-1) tag[id]=tag[ls];
	}
	void pushdown(int id)
	{
		if(tag[id]==-1) return;
		tag[ls]=tag[rs]=tag[id];
		v[ls]=v[rs]=v[id];
		tag[id]=-1;
	}
	void build(int l,int r,int id)
	{
		v[id]=tag[id]=-1;
		if(l==r)
		{
			v[id]=tag[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id,T x,int f)
	{
		if(l>=ql&&r<=qr)
		{
			if(f==1)
			{
				v[id]=tag[id]=x;
				return;
			}
			else
			{
				if(tag[id]!=-1)
				{
					if(v[id]>x) v[id]=tag[id]=__gcd(v[id],x);
					return;
				}
			}
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls,x,f);
		if(qr>mid) update(mid+1,r,rs,x,f);
		pushup(id);
	}
	void query(int l,int r,int id)
	{
		if(l==r)
		{
			printf("%lld ",v[id]);
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(){build(1,n,1);}
	void update(int l,int r,T x,int f){ql=l;qr=r;update(1,n,1,x,f);}
	void query(int l,int r){ql=l;qr=r;query(1,n,1);}
};
int main()
{
	int t,n,i,q,op,l,r;
	ll x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		segment_tree<MAX,ll> t(n);
		for(i=1;i<=n;i++) scanf("%lld",&t.a[i]);
		t.build();
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%lld",&op,&l,&r,&x);
			t.update(l,r,x,op);
		}
		t.query(1,n);
		puts("");
	}
	return 0;
}