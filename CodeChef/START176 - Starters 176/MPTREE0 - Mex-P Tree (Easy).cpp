#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
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
vector<int> mp[MAX];
int v[MAX];
ll res;
void dfs(int x,int fa,int g)
{
	g=__gcd(g,v[x]);
	for(int i=0;i<tot;i++)
	{
		if(g%p[i])
		{
			res+=p[i];
			break;
		}
	}
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,g);
	}
}
int main()
{
	int T,n,i,a,b;
	init_prime(MAX-10);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			scanf("%d",&v[i]);
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		for(i=1;i<=n;i++) 
		{
			res=0;
			dfs(i,0,0);
			printf("%lld%c",res," \n"[i==n]);
		}
	}
	return 0;
}
