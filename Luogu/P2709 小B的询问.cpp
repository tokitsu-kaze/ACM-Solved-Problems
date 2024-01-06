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
	type ans[MAX],res;
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
		res-=sqr(cnt[a[x]]);
		cnt[a[x]]++;
		res+=sqr(cnt[a[x]]);
	}
	void del(int x)
	{
		res-=sqr(cnt[a[x]]);
		cnt[a[x]]--;
		res+=sqr(cnt[a[x]]);
	}
	void work(int k)
	{
		int i,l,r,sq;
		sq=sqrt(q);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		for(i=1;i<=k;i++) cnt[i]=0;
		for(i=1;i<=q;i++) ans[i]=0;
		l=1;
		r=0;
		res=0;
		for(auto &q:qst)
		{
			while(l<q.l) del(l++);
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(r>q.r) del(r--);
			ans[q.id]=res;
		}
		for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
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
	int n,m,k,i,l,r;
	scanf("%d%d%d",&n,&m,&k);
	mo.init(n,m);
	for(i=1;i<=n;i++) scanf("%d",&mo.a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		mo.add_qst(l,r,i);
	}
	mo.work(k);
	return 0;
}
