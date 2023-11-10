#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
}tr[2];
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	ans=0;
	tr[0].init(MAX-10);
	tr[1].init(MAX-10);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=tr[1].ask(1,x-1);
		tr[1].upd(x,tr[0].ask(1,x-1));
		tr[0].upd(x,1);
	}
	printf("%lld\n",ans);
	return 0;
}
