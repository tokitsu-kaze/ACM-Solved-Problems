#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
}tr;
set<int> pos[5*MAX];
ll a[MAX];
int main()
{
	int n,m,i,j,op,l,r,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=(int)5e5;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pos[a[i]].insert(i);
	}
	for(i=2;i<=(int)5e5;i++)
	{
		for(j=i+i;j<=(int)5e5;j+=i)
		{
			pos[i].insert(pos[j].begin(),pos[j].end());
		}
	}
	tr.init(n,a);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			if(x==1) continue;
			auto it=pos[x].lower_bound(l);
			for(;it!=pos[x].end() && *it<=r;)
			{
				if(a[*it]%x==0)
				{
					tr.upd(*it,-(a[*it]-a[*it]/x));
					a[*it]/=x;
				}
				if(a[*it]<x||a[*it]%x) it=pos[x].erase(it);
				else it++;
			}
		}
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
