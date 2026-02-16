#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
const int mod=998244353;
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
struct node{int v,cnt;};
vector<node> work(int x)
{
	vector<node> res;
	while(x>1)
	{
		int t=prime[x];
		int cnt=0;
		while(x%t==0)
		{
			x/=t;
			cnt++;
		}
		res.push_back({t,cnt});
	}
	return res;
}
int a[MAX];
vector<int> s[MAX];
int main()
{
	init_prime(MAX-10);
	int T,n,i;
	ll ans,all;
	for(i=0;i<MAX;i++) s[i].clear();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<int> ha;
		for(i=1;i<=n;i++)
		{
			auto res=work(a[i]);
			for(auto &it:res)
			{
				s[it.v].push_back(it.cnt);
				ha.push_back(it.v);
			}
		}
		sort(ha.begin(),ha.end());
		ha.resize(unique(ha.begin(),ha.end())-ha.begin());
		ans=1;
		for(auto &it:ha)
		{
			sort(s[it].begin(),s[it].end());
			ans=ans*qpow(it,s[it].back())%mod;
		}
		all=ans;
		for(i=1;i<=n;i++)
		{
			auto res=work(a[i]);
			ans=all;
			for(auto &it:res)
			{
				if(it.cnt==s[it.v].back())
				{
					ans=ans*inv(qpow(it.v,s[it.v].back()))%mod;
					if(s[it.v].size()>0)
					{
						ans=ans*qpow(it.v,s[it.v][s[it.v].size()-2])%mod;
					}
				}
			}
			printf("%lld%c",ans," \n"[i==n]);
		}
		for(auto &it:ha) s[it].clear();
	}
	return 0;
}
