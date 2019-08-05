////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-27 21:23:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1636KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int n,m,flag[25][25],dir[4][2]={0,1,1,0,0,-1,-1,0},ans;
char a[25][25];
struct xy
{
	int x,y;
};
int check(int x,int y)
{
	if(a[x][y]!='#'&&!flag[x][y]&&x>=0&&x<n&&y>=0&&y<m) return 1;
	else return 0;
}
void bfs(int x,int y)
{
	int i;
	mem(flag,0);
	xy t,next; 
	queue<xy> q;
	t.x=x;
	t.y=y;
	ans=1;
	q.push(t);
	flag[t.x][t.y]=1;
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
				ans++;
				q.push(next);
				flag[next.x][next.y]=1;
			}
		}
	}
}
int main()
{
    int i,j,sx,sy; 
    while(cin>>m>>n&&(n+m))
    {
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
			}
		}
		bfs(sx,sy);
		cout<<ans<<endl;
	}
    return 0;
}