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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int n,m,mp[111][111],dp[111][111],dir[4][2]={0,1,1,0,0,-1,-1,0};
bool check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
int dfs(int x,int y)
{
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=1;
	int i,temp=0,xx,yy;
	for(i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(check(xx,yy)&&mp[x][y]>mp[xx][yy]) temp=max(temp,dfs(xx,yy));
	}
	dp[x][y]+=temp;
	return dp[x][y];
}
int main()
{
	int i,j,ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		mem(dp,-1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				ans=max(ans,dfs(i,j));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}