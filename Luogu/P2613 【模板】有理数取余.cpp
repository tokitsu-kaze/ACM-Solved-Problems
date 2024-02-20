#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const ll mod=19260817;
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
char s[MAX];
int main()
{
	int n,i;
	ll a,b;
	scanf("%s",s+1);
	n=strlen(s+1);
	a=0;
	for(i=1;i<=n;i++) a=(a*10+s[i]-'0')%mod;
	scanf("%s",s+1);
	n=strlen(s+1);
	b=0;
	for(i=1;i<=n;i++) b=(b*10+s[i]-'0')%mod;
	printf("%lld\n",a*inv(b)%mod);
	return 0;
}
