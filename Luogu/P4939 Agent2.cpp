#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
struct Fenwick_Tree
{
	#define type int
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
	int n,q,op,x,y,i;
	scanf("%d%d",&n,&q);
	tr.init(n);
	while(q--)
	{
		scanf("%d",&op);
		if(op==0)
		{
			scanf("%d%d",&x,&y);
			tr.upd(x,y,1);
		}
		else
		{
			scanf("%d",&x);
			printf("%lld\n",tr.ask(x,x));
		}
	}
	return 0;
}
