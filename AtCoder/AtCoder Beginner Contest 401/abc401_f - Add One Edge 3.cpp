#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dp[MAX],mx,rt,res;
void dfs(int x,int fa,int h)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,h+1);
	}
	if(h>mx)
	{
		mx=h;
		rt=x;
	}
	dp[x]=max(dp[x],h);
}
void work(int n)
{
	int i;
	mx=0;
	rt=1;
	dfs(rt,0,0);
	mx=0;
	for(i=1;i<=n;i++) dp[i]=0;
	dfs(rt,0,0);
	dfs(rt,0,0);
	res=max(res,mx);
}
int cnt[MAX],totcnt;
ll sum[MAX],totdp;
int main()
{
	int n,i,a,b;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	res=0;
	work(n);
	memset(cnt,0,sizeof cnt);
	memset(sum,0,sizeof sum);
	totdp=0;
	totcnt=n;
	for(i=1;i<=n;i++)
	{
//		printf("%d %d\n",i,dp[i]);
		cnt[dp[i]]++;
		sum[dp[i]]+=dp[i];
		totdp+=dp[i];
	}
	for(i=1;i<MAX;i++)
	{
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	work(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=1LL*cnt[res-dp[i]-1]*res;
		ans+=(totdp-sum[res-dp[i]-1])+1LL*(dp[i]+1)*(totcnt-cnt[res-dp[i]-1]);
	}
	printf("%lld\n",ans);
	return 0;
}

