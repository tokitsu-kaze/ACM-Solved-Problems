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
	int T,n,i,j;
	ll ans;
	init_prime(MAX-10);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		j=0;
		for(i=n;i;i--)
		{
			while(j+1<tot && 1LL*i*p[j+1]<=n) j++;
			if(i*p[j]<=n) ans+=j+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
a ab
aa aaa
x x*p
*/
