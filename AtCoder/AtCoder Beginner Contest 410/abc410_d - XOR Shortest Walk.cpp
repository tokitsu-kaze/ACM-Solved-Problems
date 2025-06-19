#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1024+10;
struct edge{int to,w;};
struct node{int x,v;};
vector<edge> mp[MAX];
int vis[MAX][MAX];
int main()
{
	int n,m,i,a,b,c,to,w,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	memset(vis,0,sizeof vis);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
	}
	queue<node> q;
	q.push({1,0});
	vis[1][0]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(auto &it:mp[t.x])
		{
			to=it.to;
			w=it.w;
			if(vis[to][t.v^w]) continue;
			vis[to][t.v^w]=1;
			q.push({to,t.v^w});
		}
	}
	ans=-1;
	for(i=0;i<MAX;i++)
	{
		if(vis[n][i])
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
