#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n,dis[2][MAX];
vector<int> mp[MAX];
void bfs(int x)
{
	int i,t;
	for(i=1;i<=n;i++) dis[x][i]=INF;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(a[i]%2==x)
		{
			dis[x][i]=0;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(auto &to:mp[t])
		{
			if(dis[x][to]>dis[x][t]+1)
			{
				dis[x][to]=dis[x][t]+1;
				q.push(to);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dis[x][i]==INF) dis[x][i]=-1;
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i-a[i]>=1) mp[i-a[i]].push_back(i);
		if(i+a[i]<=n) mp[i+a[i]].push_back(i);
	}
	bfs(0);
	bfs(1);
	for(i=1;i<=n;i++) printf("%d%c",dis[!(a[i]&1)][i]," \n"[i==n]);
	return 0;
}
