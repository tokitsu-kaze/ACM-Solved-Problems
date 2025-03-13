#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct MO_Algorithm
{
	#define type int
	struct query_info{int l,r,id;type v;};
	vector<query_info> qst;
	int n,q,a[MAX];
	type ans[MAX],res,cnt[MAX],rescnt[MAX];
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(int l,int r,int id,type v=0){qst.push_back({l,r,id,v});}
	void add(int x)
	{
		rescnt[cnt[a[x]]]--;
		cnt[a[x]]++;
		rescnt[cnt[a[x]]]++;
		res=max(res,cnt[a[x]]);
	}
	void del(int x)
	{
		rescnt[cnt[a[x]]]--;
		cnt[a[x]]--;
		rescnt[cnt[a[x]]]++;
		if(rescnt[res]==0) res--;
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
		l=1;
		r=0;
		memset(cnt,0,sizeof cnt);
		memset(rescnt,0,sizeof rescnt);
		res=0;
		for(auto &q:qst)
		{
			while(l<q.l) del(l++);
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(r>q.r) del(r--);
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
const int delta=1e5;
int main()
{
	int n,q,i,l,r;
	scanf("%d%d",&n,&q);
	mo.init(n,q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&mo.a[i]);
		mo.a[i]+=delta;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		mo.add_qst(l,r,i);
	}
	mo.work();
	for(i=1;i<=q;i++) printf("%d\n",mo.ans[i]);
	return 0;
}
