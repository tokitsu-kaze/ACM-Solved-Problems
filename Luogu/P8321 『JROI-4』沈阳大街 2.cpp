#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return qpow(x,mod-2);}
int fac[MAX],invfac[MAX];
void init_comb(int n)
{
	assert(n<MAX);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}
struct node{int v,f,cnt;};
int dp[2][MAX];
int main()
{
	int n,i,j,x,now[2],f;
	scanf("%d",&n);
	init_comb(n);
	vector<node> res;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		res.push_back({x,0,0});
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		res.push_back({x,1,0});
	}
	sort(res.begin(),res.end(),[](node x,node y){
		return x.v>y.v;
	});
	now[0]=now[1]=0;
	now[res[0].f]++;
	for(i=1;i<2*n;i++)
	{
		res[i].cnt=now[!res[i].f];
		now[res[i].f]++;
	}
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0]=1;
	for(auto &it:res)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		dp[f][0]=1;
		for(j=1;j-1<=it.cnt;j++)
		{
			dp[f][j]=(dp[!f][j]+
	1LL*dp[!f][j-1]*(it.cnt-(j-1))%mod*it.v)%mod;
		}
	}
	printf("%lld\n",1LL*dp[f][n]*invfac[n]%mod);
	return 0;
}
