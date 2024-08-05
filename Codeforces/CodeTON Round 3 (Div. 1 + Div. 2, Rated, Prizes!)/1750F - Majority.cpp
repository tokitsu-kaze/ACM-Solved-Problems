#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5005+10;
int dp[MAX][MAX],pow2[MAX],s1[MAX*2],s2[MAX*2];
int main()
{
	int n,mod,i,j,k,l;
	scanf("%d%d",&n,&mod);
	pow2[0]=1;
	for(i=1;i<=n;i++) pow2[i]=2LL*pow2[i-1]%mod;
	memset(dp,0,sizeof dp);
	memset(s1,0,sizeof s1);
	memset(s2,0,sizeof s2);
	dp[1][1]=s1[2]=1;
	for(i=2;i<=n;i++)
	{
/*		for(j=1;j<=(i-1)/2;j++)
		{
			ll tmp=0;
			for(k=j+2;j+k<i;k++)
			{
				for(l=1;j+l<k;l++)
				{
					cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					tmp+=dp[i-j-k][l];
				}
			}
			tmp%=mod;
			dp[i][j]=(dp[i][j]+dp[j][j]*tmp)%mod;
		}
*/
		for(j=1;j<=2*n;j++) s2[j]=(s2[j-1]+s1[j])%mod;
		for(j=1;j<=(i-1)/2;j++) dp[i][j]=(dp[i][j]+1LL*dp[j][j]*s2[i-j*2-1])%mod;
		dp[i][i]=pow2[i-2];
		for(j=1;j<=(i-1)/2;j++) dp[i][i]=(dp[i][i]-dp[i][j]+mod)%mod;
		for(j=1;j<=i;j++) s1[i+j]=(s1[i+j]+dp[i][j])%mod;
	}
	printf("%d\n",dp[n][n]);
	return 0;
}
