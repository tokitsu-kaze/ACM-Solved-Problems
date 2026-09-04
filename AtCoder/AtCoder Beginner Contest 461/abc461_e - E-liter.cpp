#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Fenwick_Tree
{
	#define type int
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
}tx,ty;
int prex[MAX],prey[MAX];
int main()
{
	int n,q,i,op,x;
	ll ans;
	scanf("%d%d",&n,&q);
	memset(prex,0,sizeof prex);
	memset(prey,0,sizeof prey);
	tx.init(q);
	ty.init(q);
	ans=0;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			if(!prex[x])
			{
				prex[x]=i;
				tx.upd(i,1);
				ans+=n;
			}
			else
			{
				ans+=ty.ask(prex[x]+1,i);
				tx.upd(prex[x],-1);
				prex[x]=i;
				tx.upd(prex[x],1);
			}
		}
		else
		{
			ans-=tx.ask(prey[x]+1,i);
			if(prey[x]) ty.upd(prey[x],-1);
			prey[x]=i;
			ty.upd(prey[x],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
维护每一行上一次涂黑的时间；每一列上一次涂白的时间。
涂一行时，看上一次时间和当前时间之间有多少个不同的涂白，加上；
涂一列时，看上一次时间和当前时间之间有多少个不同的涂黑，减掉。
问题转化成，区间查询种类数？
按时间线本身就是扫描线，维护每种数最后出现的位置即可。 
*/
