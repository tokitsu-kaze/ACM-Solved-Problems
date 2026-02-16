#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		n++;
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
		x++;
		for(;x<=n;x+=lowbit(x)) bit[x]+=v;
	}
	type ask(int l,int r)
	{
		l++;
		r++;
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr,trcnt;
int a[MAX];
int main()
{
	int n,q,i,op,l,r;
	ll ans;
	scanf("%d%d",&n,&q);
	tr.init(5e5);
	trcnt.init(5e5);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tr.upd(a[i],a[i]);
		trcnt.upd(a[i],1);
	}
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			tr.upd(a[l],-a[l]);
			trcnt.upd(a[l],-1);
			a[l]=r;
			tr.upd(a[l],a[l]);
			trcnt.upd(a[l],1);
		}
		else
		{
			ans=0;
			ans+=1LL*trcnt.ask(0,min(l,r))*l;
			ans+=1LL*trcnt.ask(r+1,5e5)*max(l,r);
			if(l<r) ans+=tr.ask(l+1,r);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
- ai<=r  max(l,ai)
  - ai<=l   l
  - ai>l    ai
- ai>r   max(l,r)

l<ai<=r       ai
ai<=min(l,r)  l
ai>r          max(l,r)
*/
