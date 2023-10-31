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
#define MAX 200+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int n,m,mp[11][11];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
int main()
{
	int i,j,k,flag,x,y;
//	freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)&&(n+m))
    {
		mem(mp,0);
		flag=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&mp[i][j]);
				if(mp[i][j]==0) flag=0;
			}
		}
		for(i=0;i<n&&!flag;i++)
		{
			for(j=0;j<m&&!flag;j++)
			{
				if(mp[i][j]) continue;
				for(k=0;k<4&&!flag;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(check(x,y))
					{
						if(mp[x][y]==mp[i][j])
						{
							flag=1;
							break;
						}
					}
				}
			}
		}
		if(flag) puts("No");
		else puts("Yes");
	}
    return 0;
}