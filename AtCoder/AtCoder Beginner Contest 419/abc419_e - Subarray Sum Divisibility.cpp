#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
int dp[505][505],val[505][505],a[505];
int main()
{
	int n,m,l,i,j,k;
	scanf("%d%d%d",&n,&m,&l);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=m;
	}
	for(i=1;i<=l;i++)
	{
		for(j=0;j<m;j++)
		{
			val[i][j]=0;
			for(k=i;k<=n;k+=l)
			{
				if(a[k]>j) val[i][j]+=j+m-a[k];
				else val[i][j]+=j-a[k];
			}
		}
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=l;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<m;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][(j-k+m)%m]+val[i][k]);
			}
		}
	}
	printf("%d\n",dp[l][0]);
	return 0;
}
