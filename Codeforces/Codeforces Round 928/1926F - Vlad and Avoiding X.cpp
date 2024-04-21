#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dir[4][2]={1,1,1,-1,-1,1,-1,-1};
struct node{int x,y;};
vector<node> pos[2];
const int n=7;
int mp[8][8];
void init()
{
	int i,j;
	pos[0].clear();
	pos[1].clear();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			pos[(i+j)&1].push_back({i,j});
		}
	}
}
int ck(int f)
{
	int cnt,i,x,y;
	for(auto &it:pos[f])
	{
		if(!mp[it.x][it.y]) continue;
		cnt=0;
		for(i=0;i<4;i++)
		{
			x=it.x+dir[i][0];
			y=it.y+dir[i][1];
			if(x<0||y<0||x>=n||y>=n) continue;
			cnt+=mp[x][y];
		}
		if(cnt==4) return 0;
	}
	return 1;
}
int ok;
void dfs(int x,int now,int f)
{
	if(now==0)
	{
		ok|=ck(f);
		return;
	}
	if(x==pos[f].size()) return;
	mp[pos[f][x].x][pos[f][x].y]^=1;
	dfs(x+1,now-1,f);
	mp[pos[f][x].x][pos[f][x].y]^=1;
	dfs(x+1,now,f);
}
int main()
{
	int t,i,j,ans;
	char s[11];
	init();
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<n;j++)
			{
				if(s[j]=='W') mp[i][j]=0;
				else mp[i][j]=1;
			}
		}
		ans=0;
		for(j=0;j<=1;j++)
		{
			for(i=0;i<=4;i++)
			{
				ok=0;
				dfs(0,i,j);
				if(ok)
				{
					ans+=i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
