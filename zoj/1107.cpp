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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
int mp[111][111];
int dp[111][111];
int n,k,dir[4][2]={1,0,0,1,0,-1,-1,0};
int check(int x,int y,int v)
{
	if(x<0||y<0||x>=n||y>=n||v>=mp[x][y]) return 0;
	return 1;
}
int dfs(int x,int y)
{
	int i,j,tx,ty;
	if(dp[x][y]>=0) return mp[x][y]+dp[x][y];
	dp[x][y]=0;
	for(i=0;i<4;i++)
	{
		for(j=1;j<=k;j++)
		{
			tx=x+j*dir[i][0];
			ty=y+j*dir[i][1];
			if(check(tx,ty,mp[x][y]))
			{
				dp[x][y]=max(dp[x][y],dfs(tx,ty));
			}
		}
	}
	return mp[x][y]+dp[x][y];
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&k)&&n+k>-2)
	{
		mem(mp,0);
		mem(dp,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
				dp[i][j]=-1;
			}
		}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}