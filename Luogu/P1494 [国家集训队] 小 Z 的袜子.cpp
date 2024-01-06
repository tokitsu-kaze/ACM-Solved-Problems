#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e4+10;
ll sqr(ll x){return x*x;}
struct MO_Algorithm
{
	#define type ll
	struct query_info{int l,r,id;type v;};
	vector<query_info> qst;
	int n,q,a[MAX];
	type fz[MAX],fm[MAX],res;
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(int l,int r,int id,type v=0){qst.push_back({l,r,id,v});}
	int cnt[MAX];
	void add(int x)
	{
		res+=cnt[a[x]];
		cnt[a[x]]++;
	}
	void del(int x)
	{
		cnt[a[x]]--;
		res-=cnt[a[x]];
	}
	void work()
	{
		int i,l,r,sq;
		sq=sqrt(q);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=q;i++) fz[i]=0;
		l=1;
		r=0;
		res=0;
		for(auto &q:qst)
		{
			while(l<q.l) del(l++);
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(r>q.r) del(r--);
			if(q.l==q.r)
			{
				fz[q.id]=0;
				fm[q.id]=1;
			}
			else
			{
				fz[q.id]=res;
				fm[q.id]=1ll*(q.r-q.l+1)*(q.r-q.l)/2;
				ll d=__gcd(fz[q.id],fm[q.id]);
				fz[q.id]/=d;
				fm[q.id]/=d;
			}
		}
		for(i=1;i<=q;i++) printf("%lld/%lld\n",fz[i],fm[i]);
	}
	#undef type
}mo;
/*
O(n*sqrt(q))
mo.init(n,q);
mo.add_qst(l,r,id);
mo.work();
*/
int main()
{
	int n,m,i,l,r;
	scanf("%d%d",&n,&m);
	mo.init(n,m);
	for(i=1;i<=n;i++) scanf("%d",&mo.a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		mo.add_qst(l,r,i);
	}
	mo.work();
	return 0;
}
