#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
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
}tr;
int a[MAX],n;
ll work(ll k)
{
	if(k<0) return 0;
	int i,j;
	ll now,ans;
	tr.init(n);
	ans=now=0;
	for(i=1,j=1;i<=n;i++)
	{
		while(j<=n && now+tr.ask(a[j],n)<=k)
		{
			now+=tr.ask(a[j],n);
			tr.upd(a[j],1);
			j++;
		}
		ans+=j-i;
		tr.upd(a[i],-1);
		now-=tr.ask(1,a[i]);
	}
	return ans;
}
int main()
{
	int i;
	ll k;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%lld\n",work(k)-work(k-1));
	return 0;
}
/*
4 0
1 2 3 4
*/
