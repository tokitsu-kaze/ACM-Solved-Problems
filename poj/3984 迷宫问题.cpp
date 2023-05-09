#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int a[5][5],dir[4][2]={0,1,1,0,0,-1,-1,0},ans[26][2],cnt;
struct xy
{
	int x,y;
}pre[5][5];
int check(int x,int y)
{
	if(!a[x][y]&&x>=0&&x<5&&y>=0&&y<5) return 1;
	else return 0;
}
void bfs()
{
	int i;
	xy t,next; 
	queue<xy> q;
	t.x=0;
	t.y=0;
	q.push(t);
	a[t.x][t.y]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				pre[next.x][next.y].x=t.x;
				pre[next.x][next.y].y=t.y;
				q.push(next);
				a[next.x][next.y]=1;
			}
		}
	}
}
int main()
{
    int i,j,sx,sy,temp; 
    while(cin>>a[0][0])
    {
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(i+j) cin>>a[i][j];
			}
		}
		bfs();
		mem(ans,0);
		cnt=0;
		ans[cnt][0]=4;
		ans[cnt][1]=4;
		cnt++;
		for(i=4,j=4;i>=0&&j>=0;)
		{
			if(pre[i][j].x||pre[i][j].y)
			{
				ans[cnt][0]=pre[i][j].x;
				ans[cnt][1]=pre[i][j].y;
				cnt++;
				temp=i;
				i=pre[i][j].x;
				j=pre[temp][j].y;
			}
			else
			{
				ans[cnt][0]=0;
				ans[cnt][1]=0;
				break;
			}
		}
		for(i=cnt;i>=0;i--)
		{
			printf("(%d, %d)\n",ans[i][0],ans[i][1]);
		}
	}
    return 0;
}