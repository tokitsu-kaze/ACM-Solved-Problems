#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct MO_Algorithm
{
	#define type int
	struct query_info{int l,r,id;};
	vector<query_info> qst;
	int n,q,cnt[MAX],ccnt[MAX],tmp[MAX*500],tot,a[MAX],intmp[MAX];
	ll ans[MAX];
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(query_info x){qst.push_back(x);}
	void add(int x)
	{
		ccnt[cnt[a[x]]]--;
		cnt[a[x]]++;
		ccnt[cnt[a[x]]]++;
		if(!intmp[cnt[a[x]]])
		{
			tmp[tot++]=cnt[a[x]];
			intmp[cnt[a[x]]]=1;
		}
	}
	void del(int x)
	{
		ccnt[cnt[a[x]]]--;
		cnt[a[x]]--;
		ccnt[cnt[a[x]]]++;
		if(!intmp[cnt[a[x]]])
		{
			tmp[tot++]=cnt[a[x]];
			intmp[cnt[a[x]]]=1;
		}
	}
	void work()
	{
		int i,l,r,sq,newtot;
		memset(cnt,0,sizeof cnt);
		memset(ccnt,0,sizeof ccnt);
		memset(intmp,0,sizeof intmp);
		ccnt[0]=n;
		sq=sqrt(n);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		l=1;
		r=0;
		tot=0;
		for(auto &qs:qst)
		{
			while(l>qs.l) add(--l);
			while(r<qs.r) add(++r);
			while(l<qs.l) del(l++);
			while(r>qs.r) del(r--);
			ans[qs.id]=0;
			newtot=0;
			for(i=0;i<tot;i++)
			{
				intmp[tmp[i]]=0;
				if(tmp[i]>0 && ccnt[tmp[i]]==0) continue;
				intmp[tmp[i]]=1;
				ans[qs.id]=max(ans[qs.id],1LL*tmp[i]*ccnt[tmp[i]]);
				tmp[newtot++]=tmp[i];
			}
			tot=newtot;
		}
		for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	}
	#undef type
}mo;
/*
O(n*sqrt(q))
mo.init(n,q);
mo.add_qst({l,r,id});
mo.work();
*/
int main()
{
	int n,q,i,l,r;
	scanf("%d%d",&n,&q);
	mo.init(n,q);
	for(i=1;i<=n;i++) scanf("%d",&mo.a[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		mo.add_qst({l,r,i});
	}
	mo.work();
	return 0;
}
/*
显然莫队，维护出现次数和种类数。
根据值域根号性质，出现次数最多只有根号个x，查询时直接暴力集合。
如何维护这个集合？
1.开一个值域型链表，可以O(1)加入删除。
2.或者均摊分析：
插入集合数的个数是莫队复杂度，会有根号个留下，其他都只遍历一次。 
换句话说每个数要么被遍历q次，要么被遍历1次，只有根号个数会被遍历q次。
*/
