#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
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
int comb[22][22];
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
int a[MAX];
ll sum[12];
int main()
{
	init_comb(12,12);
	int n,k,i,j,a,b,f,x;
	ll now,ans;
	scanf("%d%d",&n,&k);
	now=0;
	ans=0;
	memset(sum,0,sizeof sum);
	sum[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		now=(now+x)%mod;
		f=1;
		a=k;
		b=0;
		for(j=0;j<=k;j++)
		{
			ans+=f*qpow(now,a)*sum[b]%mod*C(k,j);
			ans%=mod;
			f*=-1;
			a--;
			b++;
		}
		for(j=0;j<=k;j++) sum[j]=(sum[j]+qpow(now,j))%mod;
	}
	if(ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;
}

