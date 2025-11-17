#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
void bf(int n)
{
	int i,j;
	map<int,int> mp;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			mp[__gcd(i,j)]++;
		}
	}
	for(auto &it:mp)
	{
		if(it.second>=it.first-1)
		{
			printf("%d %d\n",it.first,it.second);
		}
	}
}
ll dp[MAX];
vector<pair<int,ll>> res;
void work(int n)
{
	int i,j;
	res.clear();
	for(i=n;i;i--)
	{
		dp[i]=1LL*(n/i)*(n/i);
		for(j=i+i;j<=n;j+=i) dp[i]-=dp[j];
	}
	for(i=n;i>=2;i--)
	{
		dp[i]/=2;
		if(dp[i]>=i-1) res.push_back({i,dp[i]});
	}
//	for(auto &it:res) printf("%d %d\n",it.first,it.second);
}
int main()
{
//	bf(1000);
	int T,n,i;
	ll m,ans,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&m);
		work(n);
		ans=0;
		for(auto &it:res)
		{
			cnt=min(it.second,m)/(it.first-1);
			ans+=cnt*it.first;
			m-=cnt*(it.first-1);
		}
		if(m!=0) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}
