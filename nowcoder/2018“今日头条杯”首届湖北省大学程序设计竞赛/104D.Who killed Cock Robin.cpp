#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long  mod=10000007;

const long long  maxn=(long long )3e5+10;
vector<long long >v[maxn];


long long  dp[maxn];
long long sum=0;
long long  dfs(long long  x,long long  pre)
{
	long long cnt=0;
	dp[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=pre)
		{
			dfs(v[x][i],x);
			dp[x]=(dp[x]*(dp[v[x][i]]+1))%mod;
		}
	}
	sum+=dp[x];
	sum%=mod;
	return 0;
}


int  main()
{
	long long  n;

	while(scanf("%lld",&n)!=EOF)
	{
		sum=0;
		for(long long  i=0;i<maxn;i++)
		{
			v[i].clear();
		}
		for(long long  i=0;i<n-1;i++)
		{
			long long  l,r;
			scanf("%lld%lld",&l,&r);
			v[l].push_back(r);
			v[r].push_back(l);
		}
		dfs(1,1);
		printf("%lld\n",sum);

	}


}
/*
5
 1 2
 1 3
 2 4
 2 5
 */
