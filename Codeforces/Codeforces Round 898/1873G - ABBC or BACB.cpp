#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int a[MAX],b[MAX],dp[MAX][2];
int main()
{
	int t,n,i,cnt,tot;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		tot=0;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='A') cnt++;
			else
			{
				if(tot) b[tot]=cnt;
				a[++tot]=cnt;
				b[tot]=0;
				cnt=0;
			}
		}
		b[tot]=cnt;
		dp[0][0]=dp[0][1]=0;
		for(i=1;i<=tot;i++)
		{
			dp[i][0]=dp[i-1][0]+a[i];
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+b[i];
		}
		printf("%d\n",max(dp[tot][0],dp[tot][1]));
	}
	return 0;
}
