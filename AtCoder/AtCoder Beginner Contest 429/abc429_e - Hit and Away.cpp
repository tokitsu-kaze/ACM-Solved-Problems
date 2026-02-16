#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int be,x,v;};
vector<int> mp[MAX];
int dis[MAX][2],col[MAX];
char s[MAX];
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	scanf("%s",s+1);
	memset(dis,0x3f,sizeof dis);
	memset(col,0,sizeof col);
	queue<node> q;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='S') q.push({i,i,0});
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(auto &to:mp[t.x])
		{
			if(t.v+1<dis[to][0])
			{
				dis[to][1]=dis[to][0];
				dis[to][0]=t.v+1;
				col[to]=t.be;
				q.push({t.be,to,t.v+1});
			}
			else if(t.v+1<dis[to][1] && t.be!=col[to])
			{
				dis[to][1]=t.v+1;
				q.push({t.be,to,t.v+1});
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]=='D') printf("%d\n",dis[i][0]+dis[i][1]);
	}
	return 0;
}
/*
7 6
1 2
2 3
3 4
4 5
5 6
5 7
SDDDDSD

6 7
1 2
2 3
3 4
3 5
4 5
4 6
5 6
SDDDDS
*/
