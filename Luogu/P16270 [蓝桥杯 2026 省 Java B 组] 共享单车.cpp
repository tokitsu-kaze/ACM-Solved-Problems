#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int a[MAX],b[MAX];
ll dp[2][MAX];
int main()
{
	int n,m,i,j,f;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	f=0;
	memset(dp[f],0x3f,sizeof dp[f]);
	for(i=0;i<=m;i++) dp[f][i]=0;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0x3f,sizeof dp[f]);
		for(j=i;j<=m;j++)
		{
			dp[f][j]=min(dp[f][j-1],dp[!f][j-1]+abs(a[i]-b[j]));
		}
	}
	printf("%lld\n",dp[f][m]);
	return 0;
}
