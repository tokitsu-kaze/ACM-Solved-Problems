#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
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
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr,trs;
int p[MAX],res[MAX];
int main()
{
	int n,q,i,op,x;
	scanf("%d%d",&n,&q);
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		res[i]=tr.ask(p[i],n);
		tr.upd(p[i],1);
	}
	tr.init(n);
	trs.init(n);
	for(i=1;i<=n;i++)
	{
		if(!res[i]) continue;
		tr.upd(res[i],1);
		trs.upd(res[i],res[i]);
	}
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			if(res[x]) tr.upd(res[x],-1);
			if(res[x]) trs.upd(res[x],-res[x]);
			
			if(res[x+1]) tr.upd(res[x+1],-1);
			if(res[x+1]) trs.upd(res[x+1],-res[x+1]);
			
			if(p[x]>p[x+1]) res[x+1]--;
			else res[x]++;
			swap(res[x],res[x+1]);
			swap(p[x],p[x+1]);
			
			if(res[x]) tr.upd(res[x],1);
			if(res[x]) trs.upd(res[x],res[x]);
			if(res[x+1]) tr.upd(res[x+1],1);
			if(res[x+1]) trs.upd(res[x+1],res[x+1]);
	//		puts("***");
	//		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
		}
		else
		{
			if(x>=n)
			{
				puts("0");
				continue;
			}
			printf("%lld\n",trs.ask(x,n)-tr.ask(x,n)*x);
		}
	}
	return 0;
}

