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
int flag[11][11][11],flag1,n,sx,sy,sz,ex,ey,ez,dir[6][3]={0,0,1,0,1,0,1,0,0,-1,0,0,0,-1,0,0,0,-1};
char map1[11][11][11];
struct xyz
{
	int x,y,z;
	int ans;
};
int check(int x,int y,int z)
{
	if(map1[x][y][z]=='O'&&!flag[x][y][z]&&x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n) return 1;
	else return 0;
}
void bfs()
{
	int i;
	mem(flag,0);
	flag1=0;
	xyz t,next;
	queue<xyz> q;
	t.x=sx;
	t.y=sy;
	t.z=sz;
	t.ans=0;
	q.push(t);
	flag[t.x][t.y][t.z]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<6;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.z=t.z+dir[i][2];
			if(next.x==ex&&next.y==ey&&next.z==ez)
			{
				printf("%d %d\n",n,t.ans+1);
				flag1=1;
				return;
			}
			else if(check(next.x,next.y,next.z))
			{
				next.ans=t.ans+1;
				q.push(next);
				flag[next.x][next.y][next.z]=1;
			}
		}
	}
}
int main()
{
    int i,j,k;
    char s[11];
    while(~scanf("%s %d",s,&n))
    {
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					scanf("%c",&map1[j][k][i]);
				}
				getchar();
			}
		}
		cin>>sy>>sx>>sz>>ey>>ex>>ez;
		getchar();
		gets(s);
		if(sx==ex&&sy==ey&&sz==ez)
		{
			printf("%d 0\n",n);
			continue;
		}
		bfs();
		if(!flag1) puts("NO ROUTE");
	}
    return 0;
}