////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-05 19:52:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4027
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:8732KB
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
template<int sz,typename T> struct segment_tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	vector<T> v,s,tag;
	int n,ql,qr;
	segment_tree(int _n):n(_n)
	{
		v.resize(sz);
		s.resize(sz<<2);
		tag.resize(sz<<2);
	}
	void pushup(int id)
	{
		tag[id]=tag[ls]+tag[rs];
		s[id]=s[ls]+s[rs];
	}
	void pushdown(int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		int mid;
		tag[id]=0;
		if(l==r)
		{
			s[id]=v[l];
			if(s[id]<=1) tag[id]=1;
			return;
		}
		mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		int mid;
		if(l>=ql&&r<=qr&&tag[id]==r-l+1) return;
		if(l==r)
		{
			s[id]=(ll)sqrt(s[id]);
			if(s[id]<=1) tag[id]=1;
			return;
		}
		mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	T query(int l,int r,int id)
	{
		int mid;
		if(l>=ql&&r<=qr) return s[id];
		mid=(l+r)>>1;
		T res=0;
		if(ql<=mid) res+=query(l,mid,ls);
		if(qr>mid) res+=query(mid+1,r,rs);
		return res;
	}
	void build(){build(1,n,1);}
	void update(int l,int r){ql=l;qr=r;update(1,n,1);}
	T query(int l,int r){ql=l;qr=r;return query(1,n,1);}
};
int main()
{
	int n,i,op,l,r,q,cas=1;
	while(~scanf("%d",&n))
	{
		segment_tree<MAX,ll> t(n);
		for(i=1;i<=n;i++) scanf("%lld",&t.v[i]); 
		t.build();
		scanf("%d",&q);
		printf("Case #%d:\n",cas++);
		while(q--)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(l>r) swap(l,r);
			if(op) printf("%lld\n",t.query(l,r));
			else t.update(l,r);
		}
		puts("");
	}
	return 0;
}