#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX];
int in[MAX],dp[MAX];
void topsort(int n)
{
	int i;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			dp[to]=max(dp[to],dp[x]+1);
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
		dp[i]=in[i]=0;
		mp[i].clear();
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[b].push_back(a);
		in[a]++;
	}
	topsort(n);
	ans=0;
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
