#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Block
{
	#define type int
	static const int N=MAX;
	static const int size=sqrt(N);
	static const int num=N/size+1;
	int cntp[MAX],cntb[MAX],n;
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++) cntp[i]=cntb[i]=0;
	}
	void point_modify(int x,type v)
	{
		cntp[x]+=v;
	}
	void block_modify(int id,type v)
	{
		cntb[id]+=v;
	}
	type point_query(int x)
	{
		return cntp[x];
	}
	type block_query(int id)
	{
		return cntb[id];
	}
	void upd(int l,int r,type x)
	{
	    point_modify(l,x);
	    while(l<=r)
		{
		    int id=(l-1)/size+1;
		    block_modify(id,x);
		    l+=size;
		}
	}
	type ask(int l,int r)
	{
	    type ans=0;
	    while(l<=r&&r%size!=0) ans+=point_query(r),r--;
	    while(l<=r&&l%size!=1) ans+=point_query(l),l++;
	    while(l<=r)
		{
		    int id=(l-1)/size+1;
		    ans+=block_query(id);
		    l+=size;
		}
	    return ans;
	}
	#undef type
}blk,blk2;
struct MO_Algorithm
{
	#define type int
	struct query_info{int l,r,id;type a,b;};
	vector<query_info> qst;
	int n,q,a[MAX];
	type ans1[MAX],ans2[MAX];
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(int l,int r,int id,type a,type b){qst.push_back({l,r,id,a,b});}
	int cnt[MAX];
	void add(int x)
	{
		cnt[a[x]]++;
		blk.upd(a[x],a[x],1);
		if(cnt[a[x]]==1) blk2.upd(a[x],a[x],1);
	}
	void del(int x)
	{
		cnt[a[x]]--;
		blk.upd(a[x],a[x],-1);
		if(cnt[a[x]]==0) blk2.upd(a[x],a[x],-1);
	}
	void work()
	{
		int i,l,r,sq;
		sq=sqrt(q*20);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		blk.init(MAX-10);
		blk2.init(MAX-10);
		l=1;
		r=0;
		for(auto &q:qst)
		{
			while(l<q.l) del(l++);
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(r>q.r) del(r--);
			ans1[q.id]=blk.ask(q.a,q.b);
			ans2[q.id]=blk2.ask(q.a,q.b);
		}
		for(i=1;i<=q;i++) printf("%d %d\n",ans1[i],ans2[i]);
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
	int n,m,i,l,r,a,b;
	scanf("%d%d",&n,&m);
	mo.init(n,m);
	for(i=1;i<=n;i++) scanf("%d",&mo.a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&l,&r,&a,&b);
		mo.add_qst(l,r,i,a,b);
	}
	mo.work();
	return 0;
}
