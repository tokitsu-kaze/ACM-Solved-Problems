#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
ll cal(ll x)
{
	ll res=1;
	while(x>0)
	{
		res=res*(x%10)%mod;
		x/=10;
	}
	return res;
}
int main()
{
	int t,l,r,i;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		if(r-l>10)
		{
			puts("0");
			continue;
		}
		ans=1;
		for(i=l;i<=r;i++) ans=ans*cal(i)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
