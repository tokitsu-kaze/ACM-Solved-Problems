#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct MO_Algorithm
{
	#define type ll
	struct query_info{int x,y,id,sgn;};
	vector<query_info> qst;
	int n,q,a[MAX],cnt[2][MAX];
	type ans[MAX],res;
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(query_info x){qst.push_back(x);}
	void add(int x,int f)
	{
		res+=cnt[!f][a[x]];
		cnt[f][a[x]]++;
	}
	void del(int x,int f)
	{
		res-=cnt[!f][a[x]];
		cnt[f][a[x]]--;
	}
	void work()
	{
		int i,l,r,sq;
		for(auto &qs:qst)
		{
			if(qs.x>qs.y) swap(qs.x,qs.y);
		}
		sq=sqrt(n);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.x/sq!=b.x/sq) return a.x/sq<b.x/sq;
			if((a.x/sq)&1) return a.y>b.y;
			else return a.y<b.y;
		});
		l=0;
		r=0;
		res=0;
		for(i=1;i<=n;i++) cnt[0][i]=cnt[1][i]=0;
		for(i=1;i<=q;i++) ans[i]=0;
		for(auto &qs:qst)
		{
			while(l<qs.x) add(++l,0);
			while(r<qs.y) add(++r,1);
			while(l>qs.x) del(l--,0);
			while(r>qs.y) del(r--,1);
			ans[qs.id]+=qs.sgn*res;
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
	int n,q,i,l1,r1,l2,r2;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&mo.a[i]);
	scanf("%d",&q);
	mo.init(n,q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		mo.add_qst({r1,r2,i,1});
		mo.add_qst({r1,l2-1,i,-1});
		mo.add_qst({l1-1,r2,i,-1});
		mo.add_qst({l1-1,l2-1,i,1});
	}
	mo.work();
	return 0;
}
/*
询问可以看成：求 i=l1..r1, j=l2..r2，a[i]=a[j] 的 (i,j) 对数。
把询问看成矩形，然后把询问拆成4份容斥一下。
转换成求 i=1..x1, j=1..x2。
这玩意可以直接用莫队做。
要注意因为求的是2个前缀，指针移动写法跟板子不太一样。
*/
