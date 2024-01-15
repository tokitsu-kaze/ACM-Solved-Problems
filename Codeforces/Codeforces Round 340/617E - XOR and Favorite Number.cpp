#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e6+10;
struct MO_Algorithm
{
	#define type ll
	struct query_info{int l,r,id;type v;};
	vector<query_info> qst;
	int n,q,a[MAX],cnt[MAX];
	type ans[MAX],res;
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
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=q;i++) ans[i]=0;
		l=1;
		r=0;
		res=0;
		for(auto &q:qst)
		{
			while(l<q.l) del(l++,k);
			while(l>q.l) add(--l,k);
			while(r<q.r) add(++r,k);
			while(r>q.r) del(r--,k);
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
	int n,m,k,i,l,r,x;
	scanf("%d%d%d",&n,&m,&k);
	mo.init(n+1,m);
	mo.a[1]=0;
	for(i=2;i<=n+1;i++)
	{
		scanf("%d",&x);
		mo.a[i]=mo.a[i-1]^x;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		mo.add_qst(l,r+1,i);
	}
	mo.work(k);
	return 0;
}
		 	 		   	 	 		 		 	 			 	
