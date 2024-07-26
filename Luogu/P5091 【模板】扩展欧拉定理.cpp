#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e7+10;
int get_phi(int n)
{
	int ans,i;
	ans=n;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans=ans-ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans-ans/n;
	return ans;
}
ll qpow(ll a,ll b,ll p)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
char s[MAX];
int main()
{
	int i,a,m,len,phi;
	ll b;
	scanf("%d%d%s",&a,&m,s+1);
	phi=get_phi(m);
	len=strlen(s+1);
	if(len>9)
	{
		b=0;
		for(i=1;i<=len;i++) b=(b*10+s[i]-'0')%phi;
		b+=phi;
	}
	else
	{
		sscanf(s+1,"%lld",&b);
		if(b>=phi) b=b%phi+phi;
	}
	printf("%lld\n",qpow(a,b,m));
	return 0;
}
