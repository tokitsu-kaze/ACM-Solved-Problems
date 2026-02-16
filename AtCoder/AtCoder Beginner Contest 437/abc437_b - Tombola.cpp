#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1.5e5+10;
int main()
{
	int n,m,k,i,j,mp[12][12],x,cnt,ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	map<int,int> vis;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&x);
		vis[x]=1;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		cnt=0;
		for(j=1;j<=m;j++)
		{
			cnt+=vis[mp[i][j]];
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
