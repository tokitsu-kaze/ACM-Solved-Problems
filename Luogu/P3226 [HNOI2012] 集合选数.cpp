#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+1;
int n,dp[2][(1<<11)+10];
bool vis[MAX];
ll cal(int x)
{
	int i,j,s,t,cnt,f,res;
	vector<int> tmp;
	tmp.push_back(0);
	while(x<=n)
	{
		cnt=0;
		t=x;
		while(t<=n)
		{
			vis[t]=1;
			cnt++;
			t*=3;
		}
		tmp.push_back(cnt);
		x*=2;
	}
	f=0;
	dp[f][0]=1;
	for(i=1;i<tmp.size();i++)
	{
		f^=1;
		for(t=0;t<(1<<tmp[i]);t++) dp[f][t]=0;
		for(s=0;s<(1<<tmp[i-1]);s++)
		{
			if(s&(s<<1)) continue;
			for(t=0;t<(1<<tmp[i]);t++)
			{
				if(t&(t<<1)) continue;
				if(s&t) continue;
				dp[f][t]=(dp[f][t]+dp[f^1][s])%mod;
			}
		}
	}
	res=0;
	for(i=0;i<(1<<tmp.back());i++)
	{
		if(i&(i<<i)) continue;
		res=(res+dp[f][i])%mod;
	}
	return res;
}
int main()
{
	int i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) vis[i]=0;
	ans=1;
	for(i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		ans=ans*cal(i)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}

