#include <bits/stdc++.h>
using namespace std;
const int MAX=1e8+10;
int p[MAX],tot,prime[MAX];
void init(int n)
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
	int n,q,k;
	scanf("%d%d",&n,&q);
	init(n);
	while(q--)
	{
		scanf("%d",&k);
		printf("%d\n",p[k-1]);
	}
	return 0;
}
