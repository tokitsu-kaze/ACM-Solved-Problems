#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
vector<ll> res;
void init()
{
	const ll limt=1e12;
	init_prime(MAX-10);
	int i,j;
	ll a,b;
	for(i=0;i<tot;i++)
	{
		for(j=i+1;j<tot;j++)
		{
			a=1LL*p[i]*p[i];
			if(a*p[j]>limt) break;
			if(a*p[j]*p[j]>limt) break;
			while(a*p[j]*p[j]<=limt)
			{
				b=1LL*p[j]*p[j];
				while(a*b<=limt)
				{
					res.push_back(a*b);
					b*=p[j];
					if(a*b>limt) break;
					b*=p[j];
				}
				a*=p[i];
				if(a*p[j]>limt) break;
				a*=p[i];
				if(a*p[j]*p[j]>limt) break;
			}
		}
	}
//	cout<<res.size()<<endl;
	sort(res.begin(),res.end());
}
int main()
{
	init();
	int q;
	ll x;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld",&x);
		printf("%lld\n",*(--upper_bound(res.begin(),res.end(),x)));
	}
	return 0;
}
