#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
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
		return 1;
	}
}dsu;
struct edge{int to,w;};
vector<edge> mp[MAX];
int res[MAX],ok;
void dfs(int x)
{
	for(auto &it:mp[x])
	{
		if(res[it.to]==-1)
		{
			res[it.to]=(it.w^res[x]);
			dfs(it.to);
		}
		else
		{
			if(res[it.to]!=(it.w^res[x])) ok=0;
		}
	}
}
vector<int> tmp[MAX];
int main()
{
	int n,m,i,j,a,b,c,now,cnt;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		tmp[i].clear();
		mp[i].clear();
		res[i]=-1;
	}
	dsu.init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
		dsu.merge(a,b);
	}
	for(i=1;i<=n;i++) tmp[dsu.find(i)].push_back(i);
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(mp[i].size()==0)
		{
			res[i]=0;
			continue;
		}
		if(tmp[i].size()==0) continue;
		res[i]=0;
		dfs(i);
		if(!ok) break;
		now=0;
		for(j=0;j<30;j++)
		{
			cnt=0;
			for(auto &x:tmp[i]) cnt+=((res[x]>>j)&1);
			if(cnt>tmp[i].size()-cnt) now|=(1<<j);
		}
		for(auto &x:tmp[i]) res[x]^=now;
	}
	if(ok==0) puts("-1");
	else
	{
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
/*
3 2
1 2 1
2 3 2
*/
