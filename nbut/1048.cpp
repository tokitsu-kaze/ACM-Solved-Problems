#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>
#define mem(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
char mp[222][222];
int flag[222][222],dir[4][2]={0,1,1,0,0,-1,-1,0},n,m;
bool check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
void bfs(int s,int e)
{
	int i;
	queue<PII >q;
	PII t,next;
	q.push(MP(s,e));
	flag[s][e]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			next=t;
			next.fi+=dir[i][0];
			next.se+=dir[i][1];
			if(check(next.fi,next.se))
			{
				if(flag[next.fi][next.se]) continue;
				if(mp[next.fi][next.se]!=' ') continue;
				q.push(next);
				flag[next.fi][next.se]=1;
			}
		}
	}
}
int main()
{
	int i,j,ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				flag[i][j]=0;
				scanf("%c",&mp[i][j]);
			}
		}
		ans=0;
		for(i=0;i<n;i++)
		{
	//		puts(mp[i]);
			for(j=0;j<m;j++)
			{
				if(!flag[i][j]&&mp[i][j]==' ')
				{
					bfs(i,j);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}