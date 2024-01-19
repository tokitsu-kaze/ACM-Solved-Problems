#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
struct node
{
	int x,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
vector<node> mp[MAX];
int dis[MAX][105];
int bfs(int s,int n,int k)
{
	int tmp;
	memset(dis,0x3f,sizeof dis);
	priority_queue<node> q;
	q.push({s,0});
	dis[s][0]=0;
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		for(auto &it:mp[t.x])
		{
			if(t.v+1>=dis[it.x][(t.v+1)%k]) continue;
			tmp=max(0,(it.v-t.v+(k-1))/k*k);
			dis[it.x][(t.v+1)%k]=t.v+1+tmp;
			q.push({it.x,t.v+1+tmp});
		}
	}
	if(dis[n][0]==INF) return -1;
	return dis[n][0];
}
int main()
{
	int n,m,k,i,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
	}
	printf("%d\n",bfs(1,n,k));
	return 0;
}
