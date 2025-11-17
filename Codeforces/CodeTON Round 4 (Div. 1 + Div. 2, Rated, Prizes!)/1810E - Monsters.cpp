#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
struct node
{
	int x,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int v[MAX],col[MAX],vis[MAX];
vector<int> mp[MAX];
void bfs(int x,int tm)
{
	priority_queue<node> q;
	q.push({x,v[x]});
	vis[x]=tm;
	while(!q.empty())
	{
		node t=q.top();
		if(t.v>dsu.sz[dsu.find(x)]) return;
		q.pop();
		dsu.merge(t.x,x,true);
		for(auto &to:mp[t.x])
		{
			if(vis[to]<tm)
			{
				q.push({to,v[to]});
				vis[to]=tm;
			}
		}
	}
}
int main()
{
	int T,n,m,i,a,b,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
			vis[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dsu.init(n);
		cnt=1;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(v[i]==0) bfs(i,cnt++);
		}
		if(dsu.sz[dsu.find(1)]==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
1
5 4
0 2 1 0 4
1 2
2 3
3 4
1 5
*/
