#include <bits/stdc++.h>
using namespace std;
int dp[2020],w[2020],tmp[2020];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		for(j=m;j>=w[i];j--) dp[j]=(dp[j]+dp[j-w[i]])%10;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++) tmp[j]=dp[j];
		for(j=w[i];j<=m;j++) tmp[j]=(tmp[j]-tmp[j-w[i]]+10)%10;
		for(j=1;j<=m;j++) printf("%d",tmp[j]);
		puts("");
	}
	return 0;
}
