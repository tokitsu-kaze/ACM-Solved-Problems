#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
int p[MAX],phi[MAX],tot,prime[MAX];
void init_phi(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=phi[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i])
		{
			prime[i]=p[tot++]=i;
			phi[i]=i-1;
		}
		for(j=0;i*p[j]<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
ll qpow(ll a,ll b,ll p)
{
	if(p==1) return 0LL;
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
ll dfs(int p)
{
	if(p==1) return 0;
	return qpow(2,dfs(phi[p])+phi[p],p);
}
int main()
{
	int t,p;
	init_phi(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		printf("%lld\n",dfs(p));
	}
	return 0;
}
