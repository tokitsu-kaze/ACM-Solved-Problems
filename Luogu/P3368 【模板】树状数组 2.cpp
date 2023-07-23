#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX][2];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			bit[i][0]=bit[i][1]=0;
		}
	}
	int lowbit(int x){return x&(-x);}
	void _insert(int x,type v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			bit[i][0]+=v;
			bit[i][1]+=v*(x-1);
		}
	}
	type get(int x)
	{
		type res=0;
		for(int i=x;i;i-=lowbit(i))
		{
			res+=x*bit[i][0]-bit[i][1];
		}
		return res;
	}
	void upd(int l,int r,type v)
	{
		_insert(l,v);
		_insert(r+1,-v);
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
	int n,q,op,x,y,k,i;
	scanf("%d%d",&n,&q);
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		tr.upd(i,i,x);
	}
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			tr.upd(x,y,k);
		}
		else
		{
			scanf("%d",&x);
			printf("%lld\n",tr.ask(x,x));
		}
	}
	return 0;
}
