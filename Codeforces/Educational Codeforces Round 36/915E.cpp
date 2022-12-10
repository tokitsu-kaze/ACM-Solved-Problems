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
const int MAX=6e5+10;
const ll mod=1e9+7;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	int a[MAX],v[MAX<<2],tag[MAX<<2];
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
	}
	void pushdown(int id,int l,int r)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		v[ls]=(a[mid]-a[l])*(tag[id]&1);
		v[rs]=(a[r]-a[mid])*(tag[id]&1);
		tag[ls]=tag[rs]=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		mem(v,0);
		mem(tag,0);
	}
	void update(int l,int r,int id,int val)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]=(a[r]-a[l])*(val&1);
			tag[id]=val;
			return;
		}
		pushdown(id,l,r);
		int mid=(l+r)>>1;
		if(ql<mid) update(l,mid,ls,val);
		if(qr>mid) update(mid,r,rs,val);
		pushup(id);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void update(int l,int r,int val){ql=l;qr=r;update(1,n,1,val);}
}t;
int ql[MAX],qr[MAX],op[MAX];
int main()
{
	int n,q,i,tot;
	while(~scanf("%d%d",&n,&q))
	{
		tot=0;
		for(i=0;i<q;i++)
		{
			scanf("%d%d%d",&ql[i],&qr[i],&op[i]);
			ql[i]--;
			t.a[++tot]=ql[i];
			t.a[++tot]=qr[i];
		}
		sort(t.a+1,t.a+tot+1);
		tot=unique(t.a+1,t.a+tot+1)-t.a-1;
		t.build(tot);
		for(i=0;i<q;i++)
		{
			t.update(lower_bound(t.a+1,t.a+tot+1,ql[i])-t.a,lower_bound(t.a+1,t.a+tot+1,qr[i])-t.a,op[i]);
			printf("%d\n",n-t.v[1]);
		}
	}
	return 0;
}