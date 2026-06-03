#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res+=bit[x];
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]+=v;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}trcnt,tr;
const int V=3e5;
int main()
{
	int n,i,j,x;
	ll sum,ans;
	scanf("%d",&n);
	trcnt.init(V);
	tr.init(V);
	sum=ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=sum;
		sum+=x;
		for(j=x;j<=V;j+=x) ans-=trcnt.ask(j,min(j+x-1,V))*j;
		trcnt.upd(x,1);
		ans+=1LL*(i-1)*x-tr.ask(1,x);
		for(j=x;j<=V;j+=x) tr.upd(j,x);
		printf("%lld%c",ans," \n"[i==n]);
	}
	return 0;
}
/*
重要条件：ai互不相同。
考虑新增一个ai所产生的贡献，有两部分贡献分开算。
由于ai互不相同，调和级数枚举是对的。
计算过程比较自然，与值域有关，所以需要用数据结构动态维护。
*/
