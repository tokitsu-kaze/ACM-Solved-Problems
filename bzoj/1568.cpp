#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct LiChao_Segment_Tree
{
	#define type double
	#define inf -LLINF
	#define ls (id<<1)
	#define rs (id<<1|1)
	#define cmp max
	struct line
	{
		type k,b;
		void init(type _k=0,type _b=0){k=_k;b=_b;}
	}sg[MAX<<2];
	type v[MAX<<2];
	bool ext[MAX<<2];
	int ql,qr,n;
	type cal(line l,int x){return l.k*x+l.b;}
	void pushup(int id)
	{
		v[id]=cmp(v[id],v[ls]);
		v[id]=cmp(v[id],v[rs]);
	}
	void build(int l,int r,int id)
	{
		ext[id]=0;
		sg[id].init();
		v[id]=inf;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id,line qv)
	{
		if(l>=ql&&r<=qr)
		{
			if(!ext[id])
			{
				ext[id]=1;
				sg[id]=qv;
			}
			else if(cal(qv,l)>=cal(sg[id],l)&&cal(qv,r)>=cal(sg[id],r)) sg[id]=qv;
			else if(cal(qv,l)>cal(sg[id],l)||cal(qv,r)>cal(sg[id],r))
			{
				int mid=(l+r)>>1;
				if(cal(qv,mid)>cal(sg[id],mid)) swap(qv,sg[id]);
				if(cal(qv,l)>cal(sg[id],l)) update(l,mid,ls,qv);
				else update(mid+1,r,rs,qv);
			}
			v[id]=cmp(cal(sg[id],l),cal(sg[id],r));
			if(l!=r) pushup(id);
			//if ask min, change '>' to '<'
		}
		else
		{
			int mid=(l+r)>>1;
			if(ql<=mid) update(l,mid,ls,qv);
			if(qr>mid) update(mid+1,r,rs,qv);
			v[id]=cmp(cal(sg[id],l),cal(sg[id],r));
			if(l!=r) pushup(id);
		}
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=cmp(res,v[id]);
			return;
		}
		res=cmp(res,cal(sg[id],max(l,ql)));
		res=cmp(res,cal(sg[id],min(r,qr)));
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type k,type b)
	{
		ql=l;
		qr=r;
		line qv;
		qv.init(k,b);
		update(1,n,1,qv);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=inf;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
	#undef cmp
	#undef inf
}tr;
void go()
{
	int n,i,x;
	double k,b;
	char op[11];
	while(~scanf("%d",&n))
	{
		tr.build(50000);
		for(i=1;i<=n;i++)
		{
			scanf("%s",op);
			if(op[0]=='P')
			{
				scanf("%lf%lf",&b,&k);
				b=b-k;
				tr.upd(1,50000,k,b);
			}
			else
			{
				scanf("%d",&x);
				printf("%lld\n",(ll)(floor(tr.ask(x,x)/100)));
			}
		}
	}
}
