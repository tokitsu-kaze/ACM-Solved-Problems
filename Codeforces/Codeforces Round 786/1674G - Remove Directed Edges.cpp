#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dp[MAX];
vector<int> mp[MAX];
int in[MAX],out[MAX],tmpin[MAX];
vector<int> topsort(int n)
{
	queue<int> q;
	for(int it=1;it<=n;it++)
	{
		dp[it]=1;
		if(!tmpin[it]) q.push(it);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			if(in[to]>1 && out[x]>1) dp[to]=max(dp[to],dp[x]+1);
			tmpin[to]--;
			if(!tmpin[to]) q.push(to);
		}
	}
	return toplist;
}
int main()
{
	int n,m,i,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		in[i]=out[i]=tmpin[i]=0;
		mp[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		in[b]++;
		tmpin[b]++;
		out[a]++;
	}
	topsort(n);
	ans=1;
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
