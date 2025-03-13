#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dp[MAX],ans;
void dfs(int x,int fa)
{
	dp[x]=1;
	vector<int> tmp;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		tmp.push_back(dp[to]);
		if(dp[to]>=3) ans=max(ans,dp[to]+1);
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	if(mp[x].size()>=4)
	{
		assert(tmp.size()>=3);
		dp[x]=max(dp[x],tmp[0]+tmp[1]+tmp[2]+1);
	}
	if(tmp.size()>=4)
	{
		ans=max(ans,tmp[0]+tmp[1]+tmp[2]+tmp[3]+1);
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=-1;
	dfs(1,0);
//	for(i=1;i<=n;i++) printf("debug: %d %d\n",i,dp[i]);
	printf("%d\n",ans);
	return 0;
}
/*
5
1 2
1 3
1 4
1 5
17
1 3
2 3
3 5
4 5
5 6
5 7
3 8
8 9
8 10
8 11
10 12
10 13
10 14
11 15
11 16
11 17
*/
