#include <bits/stdc++.h>
using namespace std;
int m,n;
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
char a[110][110];
struct s
{
	int x,y;
}t,nex;
void bfs(int x,int y)
{
	int i,j;
	queue<s>q;
	t.x=x;
	t.y=y;
	q.push(t);
	a[t.x][t.y]='.';
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			nex.x=t.x+dir[i][0];
			nex.y=t.y+dir[i][1];
			if(a[nex.x][nex.y]=='W')
			{
				a[nex.x][nex.y]='.';
				q.push(nex);
			}
		}
	}
}
int main()
{ 
	int i,j,cnt;
	while(cin>>n>>m)
	{
		getchar();
		memset(a,'.',sizeof a);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]=='W')
				{
					cnt++;
					bfs(i,j);
				}
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
