#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-12;
const int MAX=3e5+10;
struct node{int a,c;};
ll dp[4][5050];
vector<node> res[4];
int main()
{
	int n,i,j,k,x,v,a,c;
	ll ans;
	scanf("%d%d",&n,&x);
	for(i=1;i<=3;i++) res[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&v,&a,&c);
		res[v].push_back({a,c});
	}
	memset(dp,0,sizeof dp);
	for(k=1;k<=3;k++)
	{
		for(auto &it:res[k])
		{
			for(i=x;i>=it.c;i--) dp[k][i]=max(dp[k][i],dp[k][i-it.c]+it.a);
		}
	}
	ans=0;
	for(i=0;i<=x;i++)
	{
		for(j=0;i+j<=x;j++)
		{
			ans=max(ans,min({dp[1][i],dp[2][j],dp[3][x-i-j]}));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
