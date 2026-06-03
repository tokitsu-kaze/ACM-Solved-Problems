#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct node{int to,c;};
vector<node> mp[MAX];
char col[MAX];
int dis[MAX];
int bfs(int s)
{
	int x;
	queue<int> q;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &it:mp[x])
		{
			if(col[it.to]=='.')
			{
				col[it.to]='0'+(it.c^1);
				continue;
			}
			if(col[it.to]=='0'+(it.c^1)) continue;
			if(dis[it.to]>dis[x]+1)
			{
				dis[it.to]=dis[x]+1;
				q.push(it.to);
			}
		}
	}
	if(dis[1]==INF) return -1;
	return dis[1];
}
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		col[i]='.';
		dis[i]=INF;
	}
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[b].push_back({a,c});
	}
	printf("%d\n",bfs(n));
	for(i=1;i<=n;i++)
	{
		if(col[i]=='.') col[i]='0';
	}
	col[n+1]='\0';
	puts(col+1);
	return 0;
}
