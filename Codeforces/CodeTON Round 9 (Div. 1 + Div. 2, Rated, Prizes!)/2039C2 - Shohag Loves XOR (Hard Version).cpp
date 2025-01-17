#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
ll gao(ll x,ll p)
{
	if(x<0) return 0;
	return x/p+1;
}
ll cal(ll l,ll r,ll p)
{
	return gao(r,p)-gao(l-1,p);
}
int main()
{
	int T,i;
	ll x,y,l,r,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		ans=0;
		for(i=60;~i;i--)
		{
			if(!((y>>i)&1)) continue;
			l=(y>>i)^1;
			l^=(x>>i);
			l<<=i;
			r=l+(1LL<<i)-1;
			ans+=cal(l,r,x);
		}
		if((x^y)%x==0) ans++;
		for(i=1;i<=min(3*x,y);i++)
		{
			if((i^x)%x==0) continue;
			if((i^x)%i==0) ans++;
		}
		printf("%lld\n",ans-1);
	}
	return 0;
}

