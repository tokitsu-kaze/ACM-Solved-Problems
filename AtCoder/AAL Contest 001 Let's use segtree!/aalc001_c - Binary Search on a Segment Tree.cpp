#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX],tmp[MAX];
	const int LOG=log2(MAX)+1;
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
	int lower_bound_pos(type k) // find first pos that sum{1..pos}>=v
	{
		type now=0;
		int i,pos,nex;
		pos=0;
		for(i=LOG;~i;i--)
		{
			nex=pos+(1<<i);
			if(nex<=n && now+bit[nex]<k)
			{
				now+=bit[nex];
				pos=nex;
			}
		}
		return pos+1;
	}
	int upper_bound_pos(type k) // find first pos that sum{1..pos}>v
	{
		type now=0;
		int i,pos,nex;
		pos=0;
		for(i=LOG;~i;i--)
		{
			nex=pos+(1<<i);
			if(nex<=n && now+bit[nex]<=k)
			{
				now+=bit[nex];
				pos=nex;
			}
		}
		return pos+1;
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr;
ll a[MAX];
int main()
{
	int n,q,i,op,x;
	ll y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	tr.init(n,a);
	while(q--)
	{
		scanf("%d%d%lld",&op,&x,&y);
		if(op==1)
		{
			tr.upd(x,y-a[x]);
			a[x]=y;
		}
		else if(op==2)
		{
			if(y>tr.ask(1,n)) printf("%d\n",n+1);
			else printf("%d\n",tr.lower_bound_pos(tr.ask(1,x-1)+y));
		}
		else
		{
			if(y>tr.ask(1,x)) printf("%d\n",0);
			else printf("%d\n",tr.upper_bound_pos(tr.ask(1,x)-y));
		}
	}
	return 0;
}
