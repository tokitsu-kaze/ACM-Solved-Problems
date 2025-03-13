#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=6000+10;
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
int fac[MAX],invfac[MAX];
void init_comb(int n)
{
	assert(n<MAX);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
ll A(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[n-m]%mod;
}
vector<int> mp[MAX];
char s[MAX];
ll pw24[MAX],pw26[MAX];
int main()
{
	int n,m,i,j,k,a,b,cnta,cnti,cntw,totw,noww;
	ll ans;
	pw24[0]=pw26[0]=1;
	for(i=1;i<MAX;i++)
	{
		pw24[i]=pw24[i-1]*24%mod;
		pw26[i]=pw26[i-1]*26%mod;
	}
	init_comb(MAX-10);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	totw=0;
	for(i=1;i<=n;i++) totw+=(s[i]=='?');
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='o' && s[i]!='?') continue;
		cnta=cnti=cntw=0;
		if(s[i]=='?') noww=1;
		else noww=0;
		for(auto &to:mp[i])
		{
			if(s[to]=='a') cnta++;
			else if(s[to]=='i') cnti++;
			else if(s[to]=='?') cntw++;
		}
		noww+=cntw;
		for(j=cnta;j<=cnta+cntw;j++)
		{
			for(k=cnti;k<=cnti+(cnta+cntw)-j;k++)
			{
				ans+=1LL*j*k%mod
					*C(cntw,j-cnta)%mod
					*C(cntw-(j-cnta),k-cnti)%mod
					*pw24[cnta+cnti+cntw-j-k]%mod
					*pw26[totw-noww];
				ans%=mod;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

