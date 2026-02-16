#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
}trcnt,trsum,tr2;
int a[MAX],b[MAX];
int getkth(int k)
{
	int l,r,mid;
	l=1;
	r=1e6;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(trcnt.ask(mid+1,1e6)>=k) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	int n,q,w,x,y,i,k,l;
	ll ans;
	scanf("%d%d",&n,&q);
	trcnt.init(1e6);
	trsum.init(1e6);
	tr2.init(1e6);
	k=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]==2)
		{
			k++;
			tr2.upd(a[i],1);
		}
		trcnt.upd(a[i],1);
		trsum.upd(a[i],a[i]);
	}
	while(q--)
	{
		scanf("%d%d%d",&w,&x,&y);
		if(b[w]==2)
		{
			k--;
			tr2.upd(a[w],-1);
		}
		trcnt.upd(a[w],-1);
		trsum.upd(a[w],-a[w]);
		a[w]=x;
		b[w]=y;
		if(b[w]==2)
		{
			k++;
			tr2.upd(a[w],1);
		}
		trcnt.upd(a[w],1);
		trsum.upd(a[w],a[w]);
		ans=trsum.ask(1,1e6);
		if(k==0)
		{
			printf("%lld\n",ans);
			continue;
		}
		l=getkth(k);
		ans+=trsum.ask(l+1,1e6)+(k-trcnt.ask(l+1,1e6))*l;
		assert(trcnt.ask(l,1e6)>=k);
		assert(trcnt.ask(l+1,1e6)<k);
		if(trcnt.ask(l,1e6)==k)
		{
			if(tr2.ask(l,1e6)==k)
			{
				ans-=l;
				if(k+1<=n) ans+=getkth(k+1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
假设有k个2，乘2的最好是最大的k个
如果最大的那个恰好是2，最大的那个是乘不了2的，吗
不对，如果k>1，最大的那个可以通过别的2乘，但
如果最大的k个都是2，那么有一个乘不了，只能乘最大的k-1个
否则最大k个都能乘2 
记录2的数量为k，树状数组维护是2的数的值域
查询kth为x，树状数组查询值域>=x的数有几个2
如果等于k个并且只有一个x，那么少乘2一个，
但可以把第k+1个乘2 

*/
