#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e7+10;
//x is a prime if prime[x]==x(x>=2)
const int V=2e7;
int p[V+1],tot,prime[V+1];
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
#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
uint a[MAX];
int main()
{
	init_prime();
	int n,i,j;
	uint ans;
	scanf("%d%u",&n,&seed);
	for(i=1;i<=n;i++) a[i]=getnext();
	for(i=0;i<tot;i++)
	{
		for(j=1;p[i]*j<=n;j++) a[p[i]*j]+=a[j];
	}
	ans=0;
	for(i=1;i<=n;i++) ans^=a[i];
	printf("%u\n",ans);
	return 0;
}
