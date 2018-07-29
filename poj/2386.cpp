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
#define MAX 200000+10
using namespace std;
typedef long long ll;
int m,n;
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
char a[110][110];
struct s
{
	int x,y;
}t,next;
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
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(a[next.x][next.y]=='W')
			{
				a[next.x][next.y]='.';
				q.push(next);
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
		mem(a,'.');
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