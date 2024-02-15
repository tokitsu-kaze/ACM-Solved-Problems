#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e7+10;
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
int sg[MAX];
int dfs(int x)
{
	if(sg[x]!=-1) return sg[x];
	int i,j,flag[105]={0};
	ll tmp;
	for(i=0;i<tot;i++)
	{
		tmp=1;
		while(x>=tmp)
		{
			dfs(x-tmp);
			flag[sg[x-tmp]]=1;
			tmp*=p[i];
		}
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}
void brute_force()
{
	memset(sg,-1,sizeof(sg));
	init(MAX-10);
	int n;
	for(n=1;n<=200;n++)
	{
	//	scanf("%d",&n);
		printf("%d ",n);
		if(dfs(n)) puts("October wins!");
		else puts("Roy wins!");
	}
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%6) puts("October wins!");
		else puts("Roy wins!");
	}
	return 0;
}
