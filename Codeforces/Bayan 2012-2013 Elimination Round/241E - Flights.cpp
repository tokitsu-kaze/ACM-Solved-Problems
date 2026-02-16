#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
struct Difference_Constraints
{
	#define type int
	static const int inf=INF;
	static const int N=1000+10;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,s,vis[N],cnt[N];
	void init(int _n)
	{
		s=_n+1;
		n=s;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	bool work()
	{
		int i,x,to;
		type w;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=cnt[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(i==s) continue;
			add_edge(s,i,0);
		}
		vis[s]=1;
		dis[s]=0;
		q.push(s);
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			vis[x]=0;
			for(auto &it:mp[x])
			{
				to=it.first;
				w=it.second;
				if(dis[to]>dis[x]+w)
				{
					dis[to]=dis[x]+w;
					cnt[to]=cnt[x]+1;
					if(cnt[to]>n) return false;
					if(!vis[to])
					{
						q.push(to);
						vis[to]=1;
					}
				}
			}
		}
		return true;
	}
	#undef type
}dfct;
/*
O(n*m)
dfct.init(n);  x[1],x[2],...,x[n]
dfct.add_edge(a,b,val); -> x[a]+val>=x[b]
dfct.work();
*/
struct node{int to,id;};
vector<node> mp[MAX],rmp[MAX];
int a[MAX],b[MAX],cnt[MAX],vis[MAX];
void dfs(int x,vector<node> *g)
{
	if(vis[x]) return;
	vis[x]=1;
	for(auto &it:g[x])
	{
		dfs(it.to,g);
		cnt[it.id]++;
	}
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		rmp[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		cnt[i]=0;
		mp[a[i]].push_back({b[i],i});
		rmp[b[i]].push_back({a[i],i});
	}
	for(i=1;i<=n;i++) vis[i]=0;
	dfs(1,mp);
	for(i=1;i<=n;i++) vis[i]=0;
	dfs(n,rmp);
	dfct.init(n);
	for(i=1;i<=m;i++)
	{
		if(cnt[i]!=2) continue;
		//	1<=d[b]-d[a]<=2
		dfct.add_edge(a[i],b[i],2);
		dfct.add_edge(b[i],a[i],-1);
	}
	if(!dfct.work())
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(i=1;i<=m;i++)
	{
		if(cnt[i]!=2) puts("1");
		else printf("%d\n",abs(dfct.dis[b[i]]-dfct.dis[a[i]]));
	}
	return 0;
}
