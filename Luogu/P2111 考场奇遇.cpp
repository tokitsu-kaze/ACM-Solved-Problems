#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
char s[MAX];
double dp[55][55];
int main()
{
	int n,a,q,i,j;
	double f,ans;
	scanf("%d%d%d",&n,&a,&q);
	scanf("%s",s+1);
	if(q==0) return 0*puts("1.000");
	dp[0][0]=1;
	f=a/100.0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1') f=a/100.0;
		else f=(100-a)/100.0;
		for(j=0;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j]*(1-f);
			if(j-1>=0) dp[i][j]+=dp[i-1][j-1]*f;
		}
	}
	ans=0;
	for(i=q;i<=n;i++) ans+=dp[n][i];
	printf("%.3f\n",ans);
	return 0;
}
