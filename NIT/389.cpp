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
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	int tag[MAX<<2],mx[MAX<<2],mn[MAX<<2],v[MAX];
	void pushup(int id)
	{
		mx[id]=max(mx[ls],mx[rs]);
		mn[id]=min(mn[ls],mn[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		mx[ls]+=tag[id];
		mx[rs]+=tag[id];
		mn[ls]+=tag[id];
		mn[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	PII update(int l,int r,int id)
	{
		PII res=MP(0,INF),t;
		if(l>=ql&&r<=qr)
		{
			res=MP(mx[id],mn[id]);
			tag[id]+=qv;
			mx[id]+=qv;
			mn[id]+=qv;
			return res; 
		}
		pushdown(id);
		int mid=(l+r)>>1;
		t=res;
		if(ql<=mid)	t=update(l,mid,ls);
		res.fi=max(res.fi,t.fi);
		res.se=min(res.se,t.se);
		t=res;
		if(qr>mid) t=update(mid+1,r,rs);
		res.fi=max(res.fi,t.fi);
		res.se=min(res.se,t.se);
		pushup(id);
		return res;
	}
	void query(int l,int r,int id)
	{
		if(l==r)
		{
			v[l]=tag[id];
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		query(l,mid,ls);
		query(mid+1,r,rs);
	}
	void build(int _n)
	{
		n=_n;
		memset(tag,0,((n<<2)+2)*sizeof(int));
		memset(mx,0,((n<<2)+2)*sizeof(int));
		memset(mn,0,((n<<2)+2)*sizeof(int));
	}
	void work()
	{
		int q,i;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&ql,&qr,&qv);
			PII res=update(1,n,1);
			printf("%d %d\n",res.fi,res.se);
		}
		query(1,n,1);
		for(i=1;i<=n;i++) printf("%d%c",v[i]," \n"[i==n]);
	}
	
}tree;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tree.build(n);
		tree.work();
	}
	return 0;
}
/*
2
4
3
1 2 3
2 3 1
3 4 1
7
4
1 7 1
2 6 1
3 5 1
4 4 1


0 0
3 0
1 0
3 4 2 1
0 0
1 1
2 2
3 3
1 2 3 4 3 2 1
*/