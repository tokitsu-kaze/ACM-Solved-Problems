#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct node{int x,y;};
int id[1010][1010],dmn,dmx,x[MAX],y[MAX];
vector<int> mp[MAX];
vector<node> e;
int ans[MAX];
int get_dis(int a,int b){return abs(x[a]-x[b])+abs(y[a]-y[b]);}
void add_edge(int a,int b,int c,int d)
{
	int ds,dt;
	ds=get_dis(a,b);
	dt=get_dis(c,d);
//	printf("ds:%d %d %d\n",a,b,ds);
//	printf("dt:%d %d %d\n",c,d,dt);
	if(ds<dmn||ds>dmx||dt<dmn||dt>dmx) return;
	mp[id[a][b]].push_back(id[c][d]);
	mp[id[c][d]].push_back(id[a][b]);
	e.push_back({id[a][b],id[c][d]});
}
int col[MAX],dis[MAX];
void bfs(vector<int> &key)
{
	queue<int> q;
	for(auto &it:key)
	{
		q.push(it);
		col[it]=it;
		dis[it]=0;
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			if(dis[to]>dis[x]+1)
			{
				dis[to]=dis[x]+1;
				col[to]=col[x];
				q.push(to);
			}
		}
	}
}
int a[MAX],b[MAX],c[MAX];
int main()
{
	int n,m,k,i,j,tot,u,v;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&dmn,&dmx);
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		for(j=1;j<=n;j++)
		{
			id[i][j]=++tot;
			mp[tot].clear();
			ans[tot]=dis[tot]=INF;
			col[tot]=0;
		}
	}
	scanf("%d",&k);
	vector<int> key;
	while(k--)
	{
		scanf("%d%d",&u,&v);
		key.push_back(id[u][v]);
	}
	e.clear();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(j=1;j<=n;j++)
		{
			if(c[i]==0) add_edge(a[i],j,b[i],j);
			else add_edge(j,a[i],j,b[i]);
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!(c[i]==0&&c[j]==1)) continue;
			add_edge(a[i],a[j],b[i],b[j]);
			add_edge(b[i],a[j],a[i],b[j]);
		}
	}
	bfs(key);
	for(auto &it:e)
	{
		if(col[it.x]==col[it.y]) continue;
		ans[col[it.x]]=min(ans[col[it.x]],dis[it.x]+1+dis[it.y]);
		ans[col[it.y]]=min(ans[col[it.y]],dis[it.x]+1+dis[it.y]);
	//	printf("e:%d %d\n",it.x,it.y);
	}
	for(auto &it:key)
	{
		if(ans[it]==INF) ans[it]=-1;
		printf("%d\n",ans[it]);
	}
	return 0;
}
