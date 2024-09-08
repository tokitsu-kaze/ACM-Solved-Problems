#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	int i,j,ans;
	ll n;
	init_prime(MAX-10);
	scanf("%lld",&n);
	ans=0;
	for(i=0;i<tot;i++)
	{
		for(j=i+1;j<tot;j++)
		{
			if(1LL*p[i]*p[j]*p[j]>n/p[j]) break;
			if(1LL*p[i]*p[j]*p[j]*p[j]<=n) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
