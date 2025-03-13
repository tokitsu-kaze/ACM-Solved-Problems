#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=4e5+10;
int a[MAX],sum[MAX],n;
int gao(ll x)
{
	x/=2;
	if(x<=n) return sum[x];
	if(x&1) return sum[n];
	return sum[n]^gao(x);
}
int main()
{
	int T,i;
	ll l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%lld",&n,&l,&r);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n%2==0)
		{
			n++;
			a[n]=0;
			for(i=1;i<=n/2;i++) a[n]^=a[i];
		}
		if(l<=n)
		{
			printf("%d\n",a[l]);
			continue;
		}
		sum[0]=0;
		for(i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
		printf("%d\n",gao(l));
	}
	return 0;
}
/*
1 1 1 0 0 1 1 1 1 1 1 0 0 1 1

1000
1 2 2
1
1 3 3
1
1 4 4
1
1 5 5
1
1 6 6
1
*/
