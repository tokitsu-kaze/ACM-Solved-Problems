#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
ll res[205],dp[205];
int main()
{
	int t,i,j,tot;
	ll n,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n--;
		tot=0;
		res[++tot]=0;
		dp[0]=dp[1]=1;
		n--;
		while(n>0)
		{
			dp[tot+1]=0;
			for(i=-tot-1;i<=tot+1;i++)
			{
				now=1;
				for(j=1;j<=tot;j++)
				{
					if(i>res[j]) now+=dp[j];
				}
				if(now<=n && now>dp[tot+1])
				{
					res[tot+1]=i;
					dp[tot+1]=now;
				}
			}
			n-=dp[tot+1];
			tot++;
		}
		assert(tot<=200);
		printf("%d\n",tot);
		for(i=1;i<=tot;i++) printf("%lld%c",res[i]," \n"[i==tot]);
	}
	return 0;
}
