#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2500+10;
vector<int> mp[MAX];
int dis[MAX][MAX];
void bfs(int s)
{
	int x;
	queue<int> q;
	q.push(s);
	dis[s][s]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			if(dis[s][to]>dis[s][x]+1)
			{
				dis[s][to]=dis[s][x]+1;
				q.push(to);
			}
		}
	}
}
ll v[MAX];
struct node{ll v;int x,y;};
vector<node> res[MAX];
void upd(int x,int y)
{
	node now={v[x]+v[y],x,y};
	for(auto &it:res[x])
	{
		if(it.v<now.v) swap(it,now);
	}
	if(res[x].size()<3) res[x].push_back(now);
}
int main()
{
	int n,m,k,i,j,a,b;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		res[i].clear();
		if(i>1) scanf("%lld",&v[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	memset(dis,0x3f,sizeof dis);
	for(i=1;i<=n;i++) bfs(i);
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			if(i==j) continue;
			if(dis[1][j]<=k && dis[j][i]<=k) upd(i,j);
		}
	}
	ans=0;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			if(i==j) continue;
			if(dis[i][j]>k) continue;
			for(auto &it1:res[i])
			{
				for(auto &it2:res[j])
				{
					if(it1.x==it2.x || it1.x==it2.y) continue;
					if(it1.y==it2.x || it1.y==it2.y) continue;
					ans=max(ans,it1.v+it2.v);
//					printf("%d %d %d %d %lld\n",it1.x,it1.y,it2.x,it2.y,it1.v+it2.v);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
