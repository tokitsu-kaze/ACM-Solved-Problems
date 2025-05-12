#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX],res_and[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		res_and[y]&=res_and[x];
		return 1;
	}
}dsu[31];
struct node{int to,w;};
vector<node> mp[MAX];
int main()
{
	int n,m,q,i,j,a,b,c,ok,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=0;i<=30;i++) dsu[i].init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	for(j=0;j<=30;j++)
	{
		for(i=1;i<=n;i++)
		{
			dsu[j].res_and[i]=(1<<30)-1;
			for(auto &it:mp[i]) dsu[j].res_and[i]&=it.w;
		}
	}
	for(j=0;j<=30;j++)
	{
		for(i=1;i<=n;i++)
		{
			for(auto &it:mp[i])
			{
				if((it.w>>j)&1) dsu[j].merge(i,it.to);
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		ok=0;
		for(i=0;i<=30;i++)
		{
			if(dsu[i].find(a)==dsu[i].find(b)) ok=1;
		}
		if(ok)
		{
			puts("0");
			continue;
		}
		ok=0;
		for(i=1;i<=30;i++)
		{
			x=dsu[i].find(a);
			if(dsu[i].res_and[x]==0) ok=1;
		}
		if(ok) puts("1");
		else puts("2");
	}
	return 0;
}
