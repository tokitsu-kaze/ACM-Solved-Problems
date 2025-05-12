#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int LIMT=300;
int dp[LIMT+1][MAX],a[MAX];
int main()
{
	int n,i,q,p,k,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(k=1;k<=LIMT;k++)
	{
		for(i=n;i;i--)
		{
			if(i+a[i]+k>n) dp[k][i]=1;
			else dp[k][i]=dp[k][i+a[i]+k]+1;
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&p,&k);
		ans=0;
		if(k>LIMT)
		{
			while(p<=n)
			{
				p+=a[p]+k;
				ans++;
			}
			printf("%d\n",ans);
		}
		else printf("%d\n",dp[k][p]);
	}
	return 0;
}
