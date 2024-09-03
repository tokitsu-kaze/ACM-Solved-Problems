#include <bits/stdc++.h>
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
int a[MAX],b[MAX];
int main()
{
	int n,q,i,op,x,y,tmp;
	ll ans;
	scanf("%d",&n);
	tr.init(n);
	set<int> pos;
	pos.insert(n+1);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]==1) tr.upd(i,a[i]);
		else pos.insert(i);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			if(b[x]==1)
			{
				tr.upd(x,-a[x]);
				a[x]=y;
				tr.upd(x,a[x]);
			}
			else a[x]=y;
		}
		else if(op==2)
		{
			if(b[x]==y) continue;
			if(b[x]==1) tr.upd(x,-a[x]);
			else pos.erase(x);
			b[x]=y;
			if(b[x]==1) tr.upd(x,a[x]);
			else pos.insert(x);
		}
		else
		{
			ans=0;
			while(x<=y)
			{
				tmp=min(*pos.lower_bound(x),y+1);
				ans+=tr.ask(x,tmp-1);
				if(tmp>y) break;
				if(ans+a[tmp]>ans*b[tmp]) ans+=a[tmp];
				else ans*=b[tmp];
				x=tmp+1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
