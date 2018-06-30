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
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=998244353;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	PII v[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=min(v[ls],v[rs]);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	PII query(int l,int r,int id)
	{
		PII res=MP(INF,INF);
		if(l>=ql&&r<=qr) return v[id];
		int mid=(l+r)>>1;
		if(ql<=mid) res=min(res,query(l,mid,ls));
		if(qr>mid) res=min(res,query(mid+1,r,rs));
		return res;
	}
	void upd(int l,int r,PII x)
	{
		ql=l;
		qr=r;
		qv=x;
		update(1,n,1);
	}
	PII ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1);
	}
	void build(int _n){n=_n;mem(v,0);}
	
}tr;
struct node
{
	int l,r,id;
	friend bool operator <(node a,node b)
	{
		return a.r<b.r;
	}
};
int a[MAX],ans[MAX],pre[MAX],last[MAX];
int main()
{
	int n,q,i,l,r,j;
	while(~scanf("%d",&n))
	{
		mem(last,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(!last[a[i]]) pre[i]=0;
			else pre[i]=last[a[i]];
			last[a[i]]=i;
		}
		tr.build(MAX-10);
		scanf("%d",&q);
		vector<node> res;
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			res.pb(node{l,r,i});
		}
		sort(all(res));
		r=1;
		for(i=0;i<sz(res);i++)
		{
			while(r<=res[i].r)
			{
				if(pre[r]) tr.upd(pre[r],pre[r],MP(INF,INF));
				tr.upd(r,r,MP(pre[r],a[r]));
				r++;
			}
			PII tmp=tr.ask(res[i].l,res[i].r);
			if(tmp.fi<res[i].l) ans[res[i].id]=tmp.se;
			else ans[res[i].id]=0;
		}
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
