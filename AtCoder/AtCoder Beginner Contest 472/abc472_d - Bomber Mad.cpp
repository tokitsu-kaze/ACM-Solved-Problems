#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y;};
string mp[MAX];
char s[MAX];
int n,m,k,cntx[MAX],cnty[MAX];
vector<int> dis[MAX];
void bfs()
{
	int i,j;
	queue<node> q;
	for(i=0;i<n;i++) dis[i]=vector<int>(m,INF);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(cntx[i]==0 && cnty[j]==0)
			{
				dis[i][j]=0;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int i,j,ans;
	scanf("%d%d%d",&n,&m,&k);
	memset(cntx,0,sizeof cntx);
	memset(cnty,0,sizeof cnty);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		mp[i]=string(s);
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#')
			{
				cntx[i]++;
				cnty[j]++;
			}
		}
	}
	bfs();
	ans=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#') continue;
			if(dis[i][j]<=k) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
