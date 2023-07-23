#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int mod=100003;
const int MAX=1e6+10;
vector<int> mp[MAX];
int dis[MAX],cnt[MAX],n;
void bfs(int s)
{
	int i,x;
	for(i=1;i<=n;i++)
	{
		dis[i]=INF;
		cnt[i]=0;
	}
	queue<int> q;
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			if(dis[x]+1<dis[to])
			{
				dis[to]=dis[x]+1;
				cnt[to]=cnt[x];
				q.push(to);
			}
			else if(dis[x]+1==dis[to])
			{
				cnt[to]=(cnt[to]+cnt[x])%mod;
			}
		}
	}
}
int main()
{
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	bfs(1);
	for(i=1;i<=n;i++) printf("%d\n",cnt[i]);
	return 0;
}
