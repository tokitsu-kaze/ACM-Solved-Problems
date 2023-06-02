#include <bits/stdc++.h>
using namespace std;
const int MAX=5e7+10;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot;
bool prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int a[22],ans,n;
void dfs(int x,int k,int sum)
{
	if(k==0)
	{
		ans+=(prime[sum]==0);
		return;
	}
	if(x==n+1) return;
	dfs(x+1,k-1,sum+a[x]);
	dfs(x+1,k,sum);
}
int main()
{
	int k,i;
	init(MAX-10);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	dfs(1,k,0);
	printf("%d\n",ans);
	return 0;
}
