#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
const int mod=1e9+7;
int comb[MAX][MAX];
void init_comb(int n,int m)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=min(i,m);j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
namespace DIGDP
{
	const int base=2;
	const int DIG=60+2;
	ll dp[DIG][MAX][2];
	int p[DIG],tot;
	ll dfs(int pos,int add,int sta,int n,ll z)
	{
		if(pos==tot) return !add && !sta;
		if(dp[pos][add][sta]!=-1) return dp[pos][add][sta];
		int nexsta;
		ll res=0;
		for(int i=0;i<=n;i++)
		{
			if((i&1)!=((z>>pos)&1)) continue;
			if(((i+add)&1)<p[pos]) nexsta=0;
			else if(((i+add)&1)==p[pos]) nexsta=sta;
			else nexsta=1;
			res=(res+C(n,i)*dfs(pos+1,(i+add)>>1,nexsta,n,z))%mod;
		}
		dp[pos][add][sta]=res;
		return res;
	}
	ll gao(int n,ll z,ll x)
	{
		if(x<z) return 0;
		if(x==-1) return 0;
		memset(dp,-1,sizeof dp);
		tot=0;
		while(1)
		{
			p[tot++]=x%base;
			x/=base;
			if(!x) break;
		}
		return dfs(0,0,0,n,z);
	}
}
int main()
{
	init_comb(MAX-10,MAX-10);
	int n;
	ll l,r,z;
	scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	printf("%lld\n",(DIGDP::gao(n,z,r)-DIGDP::gao(n,z,l-1)+mod)%mod);
	return 0;
}
