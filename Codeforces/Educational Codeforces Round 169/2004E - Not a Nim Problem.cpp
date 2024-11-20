#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
const int mod=998244353;
int sg[MAX];
int dfs(int x)
{
	if(sg[x]!=-1) return sg[x];
	int i,j,flag[105]={0};
	for(i=1;i<=x;i++)
	{
		if(__gcd(i,x)!=1) continue;
		flag[dfs(x-i)]=1;
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
void bf()
{
	memset(sg,-1,sizeof sg);
	sg[0]=0;
	for(int i=1;i<=100;i++) printf("%d %d\n",i,dfs(i));
}
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	sg[0]=0;
	sg[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i])
		{
			prime[i]=p[tot++]=i;
			if(i==2) sg[i]=0;
			else sg[i]=tot;
		}
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			sg[i*p[j]]=sg[p[j]];
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	int t,n,i,ans,x;
//	bf();
	init_prime(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans^=sg[x];
		}
		if(ans) puts("Alice");
		else puts("Bob");
	}
	return 0;
}

