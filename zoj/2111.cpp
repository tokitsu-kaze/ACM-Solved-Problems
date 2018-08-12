#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=6e3+10;
const ll mod=1e9+7;
int cost[111],v[111],dp[111][111],m;
vector<int> mp[111];
void dfs(int x,int pre,int now)
{
	int i,j,k,to,temp;
	temp=(cost[x]+19)/20;
	if(cost[x]==0&&m-now<=0) return;
	if(now+temp>m) return;
	for(i=temp;i<=m-now;i++)
	{
		dp[x][i]=v[x];
	}
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=pre)
		{
			dfs(to,x,now+temp);
			for(j=m-now;j>=temp;j--)
			{
				for(k=1;k<=j-temp;k++)
				{
					dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[to][k]);
				}
			}
		}
	}
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d%d",&n,&m)&&n+m!=-2)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&cost[i],&v[i]);
			mp[i].clear();
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		mem(dp,0);
		dfs(1,0,0);
		printf("%d\n",dp[1][m]);
	}
	return 0;
}