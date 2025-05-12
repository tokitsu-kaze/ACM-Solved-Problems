#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
struct Fenwick_Tree
{
	#define type int
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
struct Fenwick_Tree_LR
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
}tr2;
struct node{int l,id;};
vector<node> res[MAX];
int cnt[MAX];
int ans[MAX];
int main()
{
	int n,m,q,i,l,r;
	scanf("%d%d",&n,&m);
	n*=2;
	for(i=1;i<=n;i++) res[i].clear();
	while(m--)
	{
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		cnt[l]++;
		res[r].push_back({l,0});
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		res[r].push_back({l,i});
	}
	tr.init(n);
	tr2.init(n);
	for(i=1;i<=n;i++)
	{
		tr.upd(i,cnt[i]);
		for(auto &it:res[i])
		{
			if(it.id==0)
			{
				tr.upd(it.l,-1);
				tr2.upd(it.l,i,1);
			}
			else ans[it.id]=tr.ask(it.l,i)+tr2.ask(it.l,it.l);
		}
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
