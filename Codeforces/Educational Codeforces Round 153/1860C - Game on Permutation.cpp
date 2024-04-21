#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			bit[i]=a[i]-a[i-lowbit(i)];
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
}tr,trsg;
int p[MAX],sg[MAX];
int main()
{
	int t,n,i,ans,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		tr.init(n);
		trsg.init(n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			cnt=tr.ask(1,p[i]);
			if(cnt&&cnt==trsg.ask(1,p[i])) ans++;
			else trsg.upd(p[i],1);
			tr.upd(p[i],1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
