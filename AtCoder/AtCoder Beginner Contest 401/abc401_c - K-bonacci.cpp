#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=1e9;
int f[MAX],sum[MAX];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	n++;
	sum[0]=f[0]=0;
	for(i=1;i<=k;i++)
	{
		f[i]=1;
		sum[i]=sum[i-1]+f[i];
	}
	for(i=k+1;i<=n;i++)
	{
		f[i]=(sum[i-1]-sum[i-k-1]+mod)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}
