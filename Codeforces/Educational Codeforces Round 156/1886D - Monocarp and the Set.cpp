#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
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
char s[MAX];
int main()
{
	int n,q,i,x;
	ll ans;
	char op[2];
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	ans=1;
	for(i=2;i<n;i++)
	{
		if(s[i]=='?') ans=ans*(i-1)%mod;
	}
	if(s[1]=='?') puts("0");
	else printf("%lld\n",ans);
	while(q--)
	{
		scanf("%d%s",&x,op);
		if(x!=1)
		{
			if(s[x]=='?') ans=ans*inv(x-1)%mod;
			s[x]=op[0];
			if(s[x]=='?') ans=ans*(x-1)%mod;
		}
		else s[x]=op[0];
		if(s[1]=='?') puts("0");
		else printf("%lld\n",ans);
	}
	return 0;
}

