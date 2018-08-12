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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int n,m,flag[220][220],x,y;
int dir[4][2]={-1,0,1,0,0,1,0,-1};
char a[220][220];
struct mark
{
	int x,y,time;
	friend bool operator<(mark a,mark b)
	{
		return a.time>b.time;
	}
};
int check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='#'&&!flag[x][y]) return 1;
	return 0;
}
int bfs(int x,int y)
{
	int i;
	priority_queue<mark>q;
	mark t,next;
	t.x=x;
	t.y=y;
	t.time=0;
	q.push(t);
	flag[x][y]=1;
	while(!q.empty())
	{
		t=q.top();
		if(a[t.x][t.y]=='a') return t.time;
		q.pop();
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				if(a[next.x][next.y]=='.'||a[next.x][next.y]=='a') next.time=t.time+1;
				else if(a[next.x][next.y]=='x') next.time=t.time+2;
				flag[next.x][next.y]=1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main()
{ 
	int i,j,ans;
	while(cin>>n>>m)
	{
		mem(a,0);
		mem(flag,0);
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",&a[i]);
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='r')
				{
					x=i;
					y=j;
				}
			}
		}
		ans=bfs(x,y);
		if(ans==-1) puts("Poor ANGEL has to stay in the prison all his life.");
        else cout<<ans<<endl;
	}
    return 0;
}