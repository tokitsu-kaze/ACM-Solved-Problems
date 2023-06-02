#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[205];
ll v[205];
int main()
{
	int T,n,W,k,i,j,x,y;
	ll ans;
	scanf("%d%d%d",&k,&W,&n);
	vector<ll> dp[5005],tmp;
	for(i=1;i<=n;i++) scanf("%d%lld",&w[i],&v[i]);
	dp[0].push_back(0);
	for(i=1;i<=n;i++)
	{
		for(j=W;j>=w[i];j--)
		{
			tmp.clear();
			for(x=0,y=0;x<dp[j-w[i]].size();x++)
			{
				while(y<dp[j].size() && dp[j][y]>=dp[j-w[i]][x]+v[i])
				{
					if(tmp.size()==k) break;
					tmp.push_back(dp[j][y]);
					y++;
				}
				if(tmp.size()<k) tmp.push_back(dp[j-w[i]][x]+v[i]);
			}
			while(y<dp[j].size())
			{
				if(tmp.size()==k) break;
				tmp.push_back(dp[j][y]);
				y++;
			}
			dp[j]=tmp;
		}
	}
	ans=0;
	for(auto &it:dp[W]) ans+=it;
	printf("%lld\n",ans);
	return 0;
}

