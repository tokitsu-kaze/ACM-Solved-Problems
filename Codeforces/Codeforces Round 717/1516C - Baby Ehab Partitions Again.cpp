#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
bool dp[MAX];
int main()
{
	int n,i,j,a[105],sum;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum&1)
	{
		puts("0");
		return 0;
	}
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=sum;j>=a[i];j--) dp[j]|=dp[j-a[i]];
	}
	if(dp[sum/2]==0)
	{
		puts("0");
		return 0;
	}
	for(j=30;~j;j--)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]&1)
			{
				puts("1");
				printf("%d\n",i);
				return 0;
			}
			a[i]>>=1;
		}
	}
	return 0;
}
