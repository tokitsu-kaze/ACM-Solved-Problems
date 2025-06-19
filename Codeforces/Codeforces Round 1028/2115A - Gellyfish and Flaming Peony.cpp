#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int dp[MAX],a[MAX],n;
int cal(int x)
{
	int i,cnt,f;
	cnt=0;
	f=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=x)
		{
			if(__gcd(a[i],x)==x) cnt++;
			else return INF;
		}
		else f=0;
	}
	return cnt-f;
}
int main()
{
	int T,i,j,ans,x,g;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0x3f,sizeof dp);
		scanf("%d",&n);
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(dp[a[i]]==INF) q.push(a[i]);
			dp[a[i]]=0;
		}
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=1;i<=n;i++)
			{
				g=__gcd(a[i],x);
				if(dp[g]>dp[x]+1)
				{
					dp[g]=dp[x]+1;
					q.push(g);
				}
			}
		}
		ans=INF;
		for(i=1;i<=MAX-10;i++)
		{
			if(dp[i]==INF) continue;
			ans=min(ans,dp[i]+cal(i));
		}
		printf("%d\n",ans);
	}
	return 0;
}

