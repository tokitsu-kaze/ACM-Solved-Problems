#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=(1<<10)+5;
char s[15];
int dp[2][MAX][MAX],mp[105];
int main()
{
	int n,m,i,j,f,val,ans;
	scanf("%d%d",&n,&m);
	vector<int> sta;
	for(i=0;i<(1<<m);i++)
	{
		if((i&(i<<1)) || (i&(i<<2))) continue;
		sta.push_back(i);
	}
//	printf("%d\n",sta.size());
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		mp[i]=0;
		for(j=0;j<m;j++)
		{
			if(s[j]=='H') mp[i]|=(1<<j);
		}
	}
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	for(i=0;i<n;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		for(auto &now:sta)
		{
			if(now&mp[i]) continue;
			val=__builtin_popcount(now);
			for(auto &pre:sta)
			{
				if(now&pre) continue;
				if(i-1>=0 && (pre&mp[i-1])) continue;
				for(auto &ppre:sta)
				{
					if(now&ppre) continue;
					if(i-2>=0 && (ppre&mp[i-2])) continue;
					dp[f][now][pre]=max(dp[f][now][pre],dp[f^1][pre][ppre]+val);
				}
			}
		}
	}
	ans=0;
	for(auto &now:sta)
	{
		for(auto &pre:sta)
		{
			ans=max(ans,dp[f][now][pre]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
