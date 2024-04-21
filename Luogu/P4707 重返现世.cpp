#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
const int mod=998244353;
ll inv[MAX];
void init_inv(int n,ll p)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
ll dp[MAX][12];
int main()
{
	init_inv(MAX-10,mod);
	int n,k,m,i,j,l,x;
	ll ans;
	scanf("%d%d%d",&n,&k,&m);
	k=n-k+1;
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(j=m;j>=x;j--)
		{
			for(l=k;l;l--)
			{
				dp[j][l]=(dp[j][l]+dp[j-x][l-1]-dp[j-x][l]+mod)%mod;
			}
		}
	}
	ans=0;
	for(i=1;i<=m;i++) ans=(ans+1LL*m*inv[i]%mod*dp[i][k])%mod;
	printf("%lld\n",ans);
	return 0;
}
