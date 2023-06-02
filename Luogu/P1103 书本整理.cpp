#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
struct node{int h,w;}a[105];
bool cmp(node a,node b){return a.h<b.h;}
int dp[105][105];
int main()
{
	int n,k,i,j,l,ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].h,&a[i].w);
	sort(a+1,a+1+n,cmp);
	memset(dp,0x3f,sizeof dp);
	for(i=1;i<=n;i++)
	{
		dp[i][i-1]=0;
		for(j=0;j<=min(i-2,k);j++)
		{
			for(l=0;l<=j;l++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1-l][j-l]+abs(a[i].w-a[i-1-l].w));
			}
		}
	}
	ans=INF;
	for(i=1;i<=n;i++)
	{
		if(k-(n-i)>=0) ans=min(ans,dp[i][k-(n-i)]);
	}
	printf("%d\n",ans);
	return 0;
}

