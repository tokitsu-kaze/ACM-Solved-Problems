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
const int MAX=5e5+10;
const ll mod=1e9+7;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	int v[MAX<<2];
	void pushup(int id)
	{
		v[id]=__gcd(v[ls],v[rs]);
	}
	void pushdown(int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		v[id]=0;
		if(l==r)
		{
			scanf("%d",&v[id]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l==ql&&l==r)
		{
			v[id]=qv;
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
		int res=0;
		if(l>=ql&&r<=qr) return v[id];
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) res=__gcd(res,query(l,mid,ls));
		if(qr>mid) res=__gcd(res,query(mid+1,r,rs));
		return res;
	}
	void build(int _n){n=_n;build(1,n,1);}
	void update(int x,int v){ql=x;qr=x;qv=v;update(1,n,1);}
	int query(int l,int r){ql=l;qr=r;return query(1,n,1);}
}tree;
int main()
{
	int n,i,q,op,l,r,x,t1,t2,mid,ll,rr;
	while(~scanf("%d",&n))
	{
		tree.build(n);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				if(l==r||x==1)
				{
					puts("YES");
					continue;
				}
				ll=l;
				rr=r;
				while(l<r)
				{
					mid=(l+r)>>1;
					if(mid-1<l) t1=1;
					else t1=(tree.query(l,mid-1)%x==0);
					if(mid+1>r) t2=1;
					else t2=(tree.query(mid+1,r)%x==0);
		//			cout<<l<<" "<<mid-1<<" "<<t1<<endl;
		//			cout<<mid+1<<" "<<r<<" "<<t2<<endl;
					if(t1&&t2)
					{
						puts("YES");
						goto end;
					}
					else if(!t1&&!t2)
					{
						puts("NO");
						goto end;
					}
					else if(t1) l=mid+1;
					else r=mid;
				}
				if(l==ll) t1=1;
				else t1=(tree.query(ll,l-1)%x==0);
				if(l==rr) t2=1;
				else t2=(tree.query(l+1,rr)%x==0);
				if(t1&&t2) puts("YES");
				else puts("NO");
				end:;
			}
			else
			{
				scanf("%d%d",&l,&x);
				tree.update(l,x);
			}
		}
	}
	return 0;
}