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
typedef long long ll;
char mp[15][15];
int flag[15][15];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
	int n,m,i,j,k,ans,x,y,p,w;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0);
		mem(flag,0);
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
				if(mp[i][j]=='W')
				{
					for(k=0;k<4;k++)
					{
						x=i+dir[k][0];
						y=j+dir[k][1];
						if(x<0||y<0||x>=n||y>=m);
						else
						{
							if(mp[x][y]=='P')
							{
								ans++;
								mp[x][y]='.';
								break;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}