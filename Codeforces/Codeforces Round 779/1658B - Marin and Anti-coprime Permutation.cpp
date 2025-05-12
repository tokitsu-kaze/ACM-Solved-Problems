#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
const int mod=998244353;
ll fac[MAX];
int main()
{
	int T,n,i,ans;
	fac[0]=1;
	for(i=1;i<MAX;i++) fac[i]=fac[i-1]*i%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n&1) puts("0");
		else printf("%lld\n",fac[n/2]*fac[n/2]%mod);
	}
	return 0;
}
