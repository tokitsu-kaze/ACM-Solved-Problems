#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
vector<int> mp[MAX];
int dp[MAX],v[MAX],in[MAX];
void topsort(int n)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			dp[i]=v[i];
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			dp[to]=max(dp[to],dp[x]+v[to]);
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
}
int main()
{
	int n,m,i,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&v[i]);
		in[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		in[b]++;
	}
	topsort(n);
	ans=0;
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
