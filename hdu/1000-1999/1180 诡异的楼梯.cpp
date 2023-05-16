////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 21:44:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1180
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1572KB
//////////////////System Comment End//////////////////
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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char mp[22][22][2];
int flag[22][22];
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m||mp[x][y][0]=='*'||flag[x][y]) return 0;
	return 1;
}
void bfs(int sx,int sy)
{
	int i;
	node t,next;
	priority_queue<node> q;
	t.x=sx;
	t.y=sy;
	t.v=0;
	flag[sx][sy]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
//		cout<<t.x<<" "<<t.y<<" "<<t.v<<endl;
		if(mp[t.x][t.y][0]=='T')
		{
			printf("%d\n",t.v);
			return;
		}
		for(i=0;i<4;i++)
		{
			next=t;
			
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			if(check(next.x,next.y))
			{
				if(mp[next.x][next.y][next.v%2]=='|')
				{
					
					if(next.x-t.x==1&&check(next.x+1,next.y)) next.x++;
					else if(t.x-next.x==1&&check(next.x-1,next.y)) next.x--;
					else
					{
						next.v++;
						if(next.y-t.y==1&&check(next.x,next.y+1)) next.y++;
						else if(t.y-next.y==1&&check(next.x,next.y-1)) next.y--;
						else continue;
					}
				}
				else if(mp[next.x][next.y][next.v%2]=='-')
				{
					if(next.y-t.y==1&&check(next.x,next.y+1)) next.y++;
					else if(t.y-next.y==1&&check(next.x,next.y-1)) next.y--;
					else
					{
						next.v++;
						if(next.x-t.x==1&&check(next.x+1,next.y)) next.x++;
						else if(t.x-next.x==1&&check(next.x-1,next.y)) next.x--;
						else continue;
					}
				}
				next.v++;
				flag[next.x][next.y]=1;
				q.push(next);
			}
		}
	}
}
int main()
{
	int i,j,sx,sy;
	while(~scanf("%d%d",&n,&m)&&(n+m))
	{
		mem(flag,0);
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				scanf("%c",&mp[i][j][0]);
				mp[i][j][1]=mp[i][j][0];
				if(mp[i][j][0]=='S')
				{
					sx=i;
					sy=j;
				}
				if(mp[i][j][0]=='|') mp[i][j][1]='-';
				else if(mp[i][j][0]=='-') mp[i][j][1]='|';
			}
		}
		bfs(sx,sy); 
	}
	return 0;
}