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
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int i,n,q,l,r,op,x,t=1;
	puts("1");
	while(t--)
	{
		n=1000;
		q=1000;
		printf("%d %d\n",n,q);
		for(i=1;i<=n;i++) printf("%d ",rand()%1000+1);
		puts("");
		while(q--)
		{
			op=rand()%3+1;
			l=rand()%n+1;
			r=rand()%(n-l+1)+l;
			printf("%d %d %d",op,l,r);
			if(op==1||op==2) printf(" %lld",llrand()%(ll)1e9+1);
			puts("");
		}
	}
	return 0;
}

ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll v[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,n,q,op,l,r,val,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%lld",&v[i]);
		while(q--)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(op==1||op==2)
			{
				scanf("%d",&val);
				for(i=l;i<=r;i++)
				{
					if(op==1) v[i]=v[i]*val%mod;
					else v[i]=pow2(v[i],val);
				}
			}
			else
			{
				ll res=1;
				for(i=l;i<=r;i++)
				{
					res=res*v[i]%mod;
				}
				printf("%lld\n",res);
			}
		}
	}
	return 0;
}
*/
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
template<int MAXN,typename T> struct segment_tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	vector<T> v,tag1,tag2;
	segment_tree(int _n):n(_n)
	{
		v.resize(MAXN<<2);
		tag1.resize(MAXN<<2);
		tag2.resize(MAXN<<2);
	}
	void pushup(int id)
	{
		v[id]=v[ls]*v[rs]%mod;
	}
	void pushdown(int id,int l,int r)
	{
		int mid=(l+r)>>1;
		if(tag2[id]!=1)
		{
			tag2[ls]=tag2[ls]*tag2[id]%(mod-1);
			tag2[rs]=tag2[rs]*tag2[id]%(mod-1);
			tag1[ls]=pow2(tag1[ls],tag2[id]);
			tag1[rs]=pow2(tag1[rs],tag2[id]);
			v[ls]=pow2(v[ls],tag2[id]);
			v[rs]=pow2(v[rs],tag2[id]);
			tag2[id]=1;
		}
		if(tag1[id]!=1)
		{
			tag1[ls]=tag1[ls]*tag1[id]%mod;
			tag1[rs]=tag1[rs]*tag1[id]%mod;
			v[ls]=v[ls]*pow2(tag1[id],mid-l+1)%mod;
			v[rs]=v[rs]*pow2(tag1[id],r-mid)%mod;
			tag1[id]=1;
		}
	//	assert(v[ls]*v[rs]%mod==v[id]);
	}
	void build(int l,int r,int id)
	{
		tag1[id]=1;
		tag2[id]=1;
		v[id]=1;
		if(l==r)
		{
			scanf("%lld",&v[id]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id,int val,int f)
	{
		if(l>=ql&&r<=qr)
		{
			if(f==1)
			{
				v[id]=v[id]*pow2(val,r-l+1)%mod;
				tag1[id]=tag1[id]*val%mod;
			}
			else
			{
				v[id]=pow2(v[id],val);
				tag1[id]=pow2(tag1[id],val);
				tag2[id]=tag2[id]*val%(mod-1);
			}
			return;
		}
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls,val,f);
		if(qr>mid) update(mid+1,r,rs,val,f);
		pushup(id);
	}
	T query(int l,int r,int id)
	{
		T res=1;
		if(l>=ql&&r<=qr) return v[id];
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) res*=query(l,mid,ls);
		res%=mod;
		if(qr>mid) res*=query(mid+1,r,rs);
		res%=mod;
		return res;
	}
	void debug(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			cout<<tag1[id]<<" "<<tag2[id]<<"****"<<endl;
			return;
		}
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid) debug(l,mid,ls);
		if(qr>mid) debug(mid+1,r,rs);
	}
	void build(){build(1,n,1);}
	void update(int l,int r,int val,int f){ql=l;qr=r;update(1,n,1,val,f);}
	void update(int x){update(x,x);}
	T query(int l,int r){ql=l;qr=r;return query(1,n,1);}
	void debug(int l,int r){ql=l,qr=r,debug(1,n,1);}
};
int main()
{
//	freopen("in.txt","r",stdin);
	int t,n,q,op,l,r,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		segment_tree<MAX,ll> t(n);
		t.build();
		while(q--)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(op==1||op==2)
			{
				int x;
				scanf("%d",&x);
				t.update(l,r,x,op);
			}
			else
			{
				printf("%lld\n",t.query(l,r));
	//			t.debug(l,r);
			}
		}
		
	}
	return 0;
}

/*
10
3 9
2 2 2
1 1 1 2
2 1 1 3
1 1 2 4
2 1 2 5
1 1 3 6
2 1 3 7
3 1 1
3 2 2
3 3 3


139321901
43984311
35831808
*/