#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=998244353;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
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
int res[MAX],rtot;
void work(int x)
{
	int t;
	rtot=0;
	while(x>1)
	{
		t=prime[x];
		res[++rtot]=t;
		while(x%t==0) x/=t;
	}
}
int dp,sum[MAX];
void dfs(int x,int f,int now)
{
	if(x==rtot+1)
	{
		if(f) dp=(dp+sum[now])%mod;
		else dp=(dp-sum[now]+mod)%mod;
		return;
	}
	dfs(x+1,f,now);
	dfs(x+1,f^1,now*res[x]);
}
void upd_sum(int x,int now)
{
	if(x==rtot+1)
	{
		if(now>1) sum[now]=(sum[now]+dp)%mod;
		return;
	}
	upd_sum(x+1,now);
	upd_sum(x+1,now*res[x]);
}
int main()
{
	init_prime(MAX-10);
	int n,i,j,x;
/*	int mx=0;
	for(i=1;i<=MAX-10;i++)
	{
		work(i);
		mx=max(mx,rtot);
	}
	cout<<mx<<endl;*/
	scanf("%d",&n);
	memset(sum,0,sizeof sum);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		work(x);
		if(i==1) dp=1;
		else dp=0;
		dfs(1,0,1);
		upd_sum(1,1);
	}
	printf("%d\n",dp);
	return 0;
}

