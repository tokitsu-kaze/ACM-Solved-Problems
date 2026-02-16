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
ll a[MAX];
int main()
{
	int n,q,i,op,l,r,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	tr.init(n,a);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(x,-a[x]);
			tr.upd(x+1,-a[x+1]);
			swap(a[x],a[x+1]);
			tr.upd(x,a[x]);
			tr.upd(x+1,a[x+1]);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",tr.ask(l,r));
		}
	}
	return 0;
}
