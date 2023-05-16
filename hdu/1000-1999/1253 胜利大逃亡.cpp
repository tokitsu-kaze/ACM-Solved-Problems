////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-18 20:50:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1253
////Problem Title: 
////Run result: Accept
////Run time:1778MS
////Run memory:2324KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int mp[55][55][55];
int a,b,c,d,dir[6][3]={1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1};
struct node
{
	int x,y,z,v;
};
int check(int x,int y,int z)
{
	if(x<0||y<0||z<0||x>=a||y>=b||z>=c||mp[x][y][z]) return 0;
	return 1;
}
void bfs()
{
	int i;
	node t,next;
	queue<node> q;
	t.x=0;
	t.y=0;
	t.z=0;
	t.v=0;
	mp[0][0][0]=1;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==a-1&&t.y==b-1&&t.z==c-1&&t.v<=d)
		{
			printf("%d\n",t.v);
			return;
		}
		for(i=0;i<6;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.z=t.z+dir[i][2];
			if(check(next.x,next.y,next.z))
			{
				next.v=t.v+1;
				if(next.v<=d)
				{
					q.push(next);
					mp[next.x][next.y][next.z]=1;
				}
			}
		}
	}
	puts("-1");
}
int main()
{
    int t,i,j,k;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
			scanf("%d%d%d%d",&a,&b,&c,&d);
			mem(mp,0);
			for(i=0;i<a;i++)
			{
				for(j=0;j<b;j++)
				{
					for(k=0;k<c;k++)
					{
						scanf("%d",&mp[i][j][k]);
					}
				}
			}
			if(mp[a-1][b-1][c-1])
			{
				puts("-1");
				continue;
			}
			bfs();
		}
    }
    return 0;
}