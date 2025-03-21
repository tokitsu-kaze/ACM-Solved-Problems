#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=2e5+10;
struct MO_Algorithm
{
	#define type ll
	struct query_info{int l,r,id;type v;};
	vector<query_info> qst;
	int n,q,a[MAX];
	type ans[MAX],cnt[MAX],res;
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(int l,int r,int id,type v=0){qst.push_back({l,r,id,v});}
	void add(int x,int k)
	{
		res+=cnt[a[x]^k];
		cnt[a[x]]++;
	}
	void del(int x,int k)
	{
		cnt[a[x]]--;
		res-=cnt[a[x]^k];
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
		l=0;
		r=-1;
		memset(cnt,0,sizeof cnt);
		res=0;
		for(auto &q:qst)
		{
			while(l<q.l) del(l++,k);
			while(l>q.l) add(--l,k);
			while(r<q.r) add(++r,k);
			while(r>q.r) del(r--,k);
			ans[q.id]=res;
		}
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
	int n,q,k,i,l,r;
	scanf("%d%d%d",&n,&q,&k);
	mo.init(n,q);
	mo.a[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&mo.a[i]);
		mo.a[i]^=mo.a[i-1];
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		l--;
		mo.add_qst(l,r,i);
	}
	mo.work(k);
	for(i=1;i<=q;i++) printf("%lld\n",mo.ans[i]);
	return 0;
}
