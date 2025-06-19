#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
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
struct node{int x,y;}e[MAX];
vector<int> mp[MAX];
int fa[MAX],l[MAX],r[MAX],tot,id[MAX];
void dfs(int x,int pre)
{
	l[x]=++tot;
	fa[x]=pre;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int main()
{
	int n,i,q,op,x,w,a,b;
	ll sum;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].y);
		mp[e[i].x].push_back(e[i].y);
		mp[e[i].y].push_back(e[i].x);
	}
	tot=0;
	dfs(1,0);
	tr.init(n);
	for(i=1;i<=n;i++) tr.upd(i,1);
	sum=n;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&w);
			tr.upd(l[x],w);
			sum+=w;
		}
		else
		{
			a=e[x].x;
			b=e[x].y;
			if(fa[a]==b) swap(a,b);
			printf("%lld\n",abs(2*tr.ask(l[b],r[b])-sum));
		}
	}
	return 0;
}
