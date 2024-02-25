#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=4e4+10;
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
int main()
{
	int n,i,ans;
	init_phi(MAX-10);
	scanf("%d",&n);
	if(n==1) return 0*puts("0");
	ans=1;
	for(i=1;i<n;i++) ans+=phi[i]*2;
	printf("%d\n",ans);
	return 0;
}

