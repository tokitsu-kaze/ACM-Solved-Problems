#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int mod;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
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
struct node{int x,cnt;};
vector<node> gao(int x)
{
	vector<node> res;
	while(x>1)
	{
		int tmp=prime[x];
		int cnt=0;
		while(x%tmp==0)
		{
			x/=tmp;
			cnt++;
		}
		res.push_back({tmp,cnt});
	}
	return res;
}
vector<int> facp[MAX];
int res[MAX][MAX],now[MAX];
int c[MAX];
int main()
{
	init_prime(MAX-10);
	int T,n,i,j,sum,ok;
	ll ans;
	memset(res,0,sizeof res);
	memset(now,0,sizeof now);
	facp[1].clear();
	for(i=2;i<=MAX-10;i++)
	{
		auto tmp=gao(i);
		facp[i]=facp[i-1];
		for(j=1;j<=5000;j++) res[i][j]=res[i-1][j];
		for(auto &it2:tmp)
		{
			res[i][it2.x]+=it2.cnt;
			ok=0;
			for(auto &it:facp[i])
			{
				if(it==it2.x)
				{
					ok=1;
					break;
				}
			}
			if(!ok) facp[i].push_back(it2.x);
		}
	}
	scanf("%d%d",&T,&mod);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			sum+=c[i];
		}
		for(auto &it:facp[sum]) now[it]=res[sum][it];
		for(i=1;i<=n;i++)
		{
			for(auto &it:facp[c[i]]) now[it]-=res[c[i]][it];
		}
		ans=1;
		for(auto &it:facp[sum])
		{
			ans=ans*qpow(it,now[it])%mod;
			now[it]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
