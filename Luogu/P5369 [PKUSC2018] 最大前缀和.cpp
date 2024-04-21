#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=(1<<20)+10;
const int mod=998244353;
int f[MAX][2],g[MAX];
ll s[MAX];
int main()
{
	int n,i,j,k,a[22],ans;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<(1<<n);i++)
	{
		s[i]=0;
		for(j=0;j<n;j++)
		{
			if((i>>j)&1) s[i]+=a[j];
		}
	}
	memset(f,0,sizeof f);
	f[0][0]=f[0][1]=1;
	// 0 is true prefix
	// 1 is suffix of prefix, sum>=0
	for(i=0;i<(1<<n);i++)
	{
		for(j=0;j<n;j++)
		{
			if(!(i>>j)&1) continue;
			if(s[i]>=0) f[i][1]=(f[i][1]+f[i^(1<<j)][1])%mod;
			f[i][0]=(f[i][0]+f[i^(1<<j)][1])%mod;
		}
	}
	memset(g,0,sizeof g);
	g[0]=1;
	for(i=0;i<(1<<n);i++)
	{
		for(j=0;j<n;j++)
		{
			if(!(i>>j)&1) continue;
			if(s[i]<0) g[i]=(g[i]+g[i^(1<<j)])%mod;
		}
	}
	ans=0;
	for(i=0;i<(1<<n);i++)
	{
		s[i]=(s[i]%mod+mod)%mod;
		ans=(ans+1LL*s[i]*f[i][0]%mod*g[i^((1<<n)-1)])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
