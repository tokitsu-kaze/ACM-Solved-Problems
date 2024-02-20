#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
vector<int> pos[MAX];
int dp[MAX][2],cnt[MAX];
int main()
{
	int t,n,m,i,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			pos[i].clear();
			cnt[i]=0;
			memset(dp[i],0,sizeof dp[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			pos[r].push_back(l);
			cnt[l]++;
		}
		multiset<int> s;
		for(i=1;i<=n;i++)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=0;
			while(cnt[i]>0)
			{
				cnt[i]--;
				s.insert(i);
			}
			if(s.size()) dp[i][1]=max(dp[i][1],dp[*s.begin()][0]+(int)s.size());
			for(auto &it:pos[i]) s.erase(s.find(it));
	//		printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}
