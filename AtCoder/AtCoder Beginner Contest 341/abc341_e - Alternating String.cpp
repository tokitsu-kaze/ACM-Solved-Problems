#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
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
}tr;
struct Fenwick_Tree_XOR
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
			res^=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]^=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)^get(l-1);
	}
	#undef type
}trxor;
char s[MAX];
int main()
{
	int n,q,i,op,l,r;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	tr.init(n);
	for(i=1;i<n;i++)
	{
		if(s[i]==s[i+1]) tr.upd(i,1);
	}
	trxor.init(n);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			trxor.upd(i,1);
			if(i+1<=n) trxor.upd(i+1,1);
		}
	}
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			if(l>1)
			{
				if(trxor.ask(1,l-1)==trxor.ask(1,l))
				{
					tr.upd(l-1,-1);
				}
				else tr.upd(l-1,1);
			}
			if(r<n)
			{
				if(trxor.ask(1,r)==trxor.ask(1,r+1))
				{
					tr.upd(r,-1);
				}
				else tr.upd(r,1);
			}
			trxor.upd(l,1);
			if(r<n) trxor.upd(r+1,1);
		}
		else
		{
			if(tr.ask(l,r-1)==0) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
