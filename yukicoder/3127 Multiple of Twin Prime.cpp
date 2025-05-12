#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
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
	int T,i;
	ll x;
	init_prime(MAX-10);
	vector<ll> res;
	res.push_back(-1);
	for(i=1;i<tot;i++)
	{
		if(p[i-1]+2==p[i]) res.push_back(1LL*p[i-1]*p[i]);
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&x);
		printf("%lld\n",*--upper_bound(res.begin(),res.end(),x));
	}
	return 0;
}
