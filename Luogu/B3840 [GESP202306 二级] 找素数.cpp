#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p[tot++]=i;
		for(j=i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
int cal(int n)
{
	init(n);
	return tot;
}
int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%d\n",cal(r)-cal(l-1));
	return 0;
}
