#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
//x is a prime if prime[x]==x(x>=2)
const int V=1e6;
int p[V+5],tot,prime[V+5];
void init_prime()
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=V;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=V;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	int n,i,ans;
	init_prime();
	scanf("%d",&n);
	ans=0;
	for(i=0;i<tot;i++)
	{
		if(p[i]>n) break;
		if(n-p[i]<p[i]) break;
		if(prime[n-p[i]]==n-p[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
