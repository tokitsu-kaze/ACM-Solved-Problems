#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
}tr;
vector<int> mp[MAX];
int l[MAX],r[MAX],id[MAX],tot,v[MAX];
void dfs(int x,int fa)
{
	id[x]=++tot;
	l[x]=tot;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int main()
{
	int n,m,i,a,b,op,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&v[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	tot=0;
	dfs(1,0);
	tr.init(n);
	for(i=1;i<=n;i++) tr.upd(id[i],v[i]);
	while(m--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			tr.upd(id[x],v[x]^y);
			v[x]=y;
		}
		else printf("%d\n",tr.ask(l[x],r[x]));
	}
	return 0;
}

