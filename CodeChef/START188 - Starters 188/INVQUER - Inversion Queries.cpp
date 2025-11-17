#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
ll pre[MAX],suf[MAX];
int a[MAX];
int main()
{
	int T,n,q,i,l,r;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		tr.init(n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			suf[a[i]]=tr.ask(a[i]+1,n);
			tr.upd(a[i],1);
			ans+=suf[a[i]];
		}
		for(i=n-1;i;i--) suf[i]+=suf[i+1];
		tr.init(n);
		for(i=n;i;i--)
		{
			pre[a[i]]=tr.ask(1,a[i]-1);
			tr.upd(a[i],1);
		}
		for(i=2;i<=n;i++) pre[i]+=pre[i-1];
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l==r) puts("0");
			else printf("%lld\n",ans-pre[l]-suf[r]);
		}
	}
	return 0;
}

