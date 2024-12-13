#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e6+10;
const int mod=998244353;
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
	int i,j;
	ll n,ans,tmp;
	init_prime(MAX-10);
	scanf("%lld",&n);
	ans=0;
	for(i=0,j=tot-1;i<tot;i++)
	{
		while(j>=0 && (i==j || 1LL*p[i]*p[i]>n/(1LL*p[j]*p[j]))) j--;
		ans+=max(0,j-i);
	}
	for(i=0;i<tot;i++)
	{
		tmp=1;
		for(j=0;j<8;j++)
		{
			if(tmp>n/p[i])
			{
				tmp=n+1;
				break;
			}
			tmp*=p[i];
		}
		if(tmp<=n) ans++;
		else break;
	}
	printf("%lld\n",ans);
	return 0;
}

