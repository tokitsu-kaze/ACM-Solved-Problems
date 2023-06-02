#include <bits/stdc++.h>
using namespace std;
int w[105],v[105];
int main()
{
	int T,n,W,k,i,j,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&W,&k);
		set<int> dp[1005],s;
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		for(i=1;i<=n;i++) scanf("%d",&w[i]);
		dp[0].insert(0);
		for(i=1;i<=n;i++)
		{
			for(j=W;j>=w[i];j--)
			{
				for(auto &it:dp[j-w[i]])
				{
					dp[j].insert(it+v[i]);
					if(dp[j].size()>k) dp[j].erase(dp[j].begin());
				}
			}
		}
		for(i=1;i<=W;i++)
		{
			for(auto &it:dp[i])
			{
				s.insert(it);
				if(s.size()>k) s.erase(s.begin());
			}
		}
		if(s.size()<k) puts("0");
		else printf("%d\n",*s.begin());
	}
	return 0;
}

