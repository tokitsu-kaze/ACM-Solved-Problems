#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct Fenwick_Tree
{
	#define type ll
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
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
int main()
{
	int n,q,op,x,y,i;
	scanf("%d%d",&n,&q);
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		tr.upd(i,x);
	}
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) tr.upd(x,y);
		else printf("%lld\n",tr.ask(x,y));
	}
	return 0;
}
