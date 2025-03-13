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
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}trsum,trcnt;
int a[MAX];
int main()
{
	int T,n,k,i,l,r,mid;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		trsum.init(n);
		trcnt.init(n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			trsum.upd(a[i],a[i]);
			trcnt.upd(a[i],1);
		}
		ans=0;
		for(i=1;i<k;i++)
		{
			trsum.upd(a[i],-a[i]);
			trcnt.upd(a[i],-1);
		}
		for(i=k;i<=n;i++)
		{
			trsum.upd(a[i],-a[i]);
			trcnt.upd(a[i],-1);
			l=1;
			r=n;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(trcnt.ask(1,mid)>=(n-k+1)/2) r=mid;
				else l=mid+1;
			}
//			printf("%d %d\n",i,l);
			if((n-k)&1) ans=max(ans,2*trsum.ask(1,l)-l);
			else ans=max(ans,2*trsum.ask(1,l));
			trsum.upd(a[i-k+1],a[i-k+1]);
			trcnt.upd(a[i-k+1],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
