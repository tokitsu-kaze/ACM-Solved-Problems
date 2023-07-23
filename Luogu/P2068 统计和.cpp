#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
	int n,q,x,y,i;
	char op[2];
	scanf("%d%d",&n,&q);
	tr.init(n);
	while(q--)
	{
		scanf("%s%d%d",op,&x,&y);
		if(op[0]=='x') tr.upd(x,y);
		else printf("%lld\n",tr.ask(x,y));
	}
	return 0;
}
