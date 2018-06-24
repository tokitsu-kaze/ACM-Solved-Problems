////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-18 21:06:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2952
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2356KB
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
char mp[111][111];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
void dfs(int x,int y)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(mp[x+dir[i][0]][y+dir[i][1]]=='#')
		{
			mp[x+dir[i][0]][y+dir[i][1]]='.';
			dfs(x+dir[i][0],y+dir[i][1]);
		}
	}
	return;
}
int main()
{
    int n,m,i,j,ans,t;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
			scanf("%d%d",&n,&m);
			mem(mp,0);
			for(i=0;i<n;i++)
			{
				getchar();
				scanf("%s",mp[i]);
			}
			ans=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(mp[i][j]=='#')
					{
						ans++;
						dfs(i,j);
					}
				}
			}
			printf("%d\n",ans);
		}
    }
    return 0;
}