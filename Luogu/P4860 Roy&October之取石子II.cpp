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
	dfs(x-1);
	flag[sg[x-1]]=1;
	for(i=0;i<tot&&x-p[i]>=0;i++)
	{
		dfs(x-p[i]);
		flag[sg[x-p[i]]]=1;
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
	sg[0]=0;
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
//	brute_force();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%4) puts("October wins!");
		else puts("Roy wins!");
	}
	return 0;
}
