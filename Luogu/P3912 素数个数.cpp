#include<bits/stdc++.h>
using namespace std;
const int MAX=1e8+10;
const int MAXP=6e6+10;
int p[MAXP],tot;
bool prime[MAX];
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
	int n;
	scanf("%d",&n);
	init(n);
	printf("%d\n",tot);
	return 0;
}
