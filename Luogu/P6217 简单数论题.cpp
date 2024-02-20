#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const ll mod=1e9+7;
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
ll inv(ll x){return qpow(x,mod-2);}
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
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
vector<pair<int,int>> work(int x)
{
	int t,cnt;
	vector<pair<int,int>> res;
	while(x>1)
	{
		t=prime[x];
		cnt=0;
		while(x%t==0)
		{
			x/=t;
			cnt++;
		}
		res.push_back({t,cnt});
	}
	return res;
}
vector<int> pos[MAX];
ll a[MAX],bit[MAX];
int cal(int l,int r,int x)
{
	return upper_bound(pos[x].begin(),pos[x].end(),r)
		-lower_bound(pos[x].begin(),pos[x].end(),l);
}
int main()
{
	int n,q,i,j,l,r,x,now,cnt;
	ll fz,fm;
	init(MAX-10);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) pos[i].clear();
	bit[0]=1;
	vector<pair<int,int>> res;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		bit[i]=bit[i-1]*a[i]%mod;
		res=work(a[i]);
		for(auto &it:res)
		{
			now=1;
			for(j=1;j<=it.second;j++)
			{
				now*=it.first;
				pos[now].push_back(i);
			}
		}
	}
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		fz=bit[r]*inv(bit[l-1])%mod*qpow(x,r-l+1)%mod;
		fm=1;
		res=work(x);
		for(auto &it:res)
		{
			now=1;
			cnt=0;
			for(j=1;j<=it.second;j++)
			{
				now*=it.first;
				cnt+=cal(l,r,now);
			}
			fm=fm*qpow(it.first,cnt)%mod;
		}
		printf("%lld\n",fz*inv(fm)%mod);
	}
	return 0;
}
/*
(al*...*ar)*x^(r-l+1)/(gcd(x,al)*...*gcd(x,ar))
*/
