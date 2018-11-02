#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n=600851475143LL,ans;
	ll sq=sqrt(n+0.5);
	ans=0;
	for(ll i=2;i<=sq;i++)
	{
		while(n%i==0)
		{
			ans=max(ans,i);
			n/=i;
		}
	}
	if(n!=1) ans=max(ans,n);
	printf("%lld\n",ans);
	return 0;
}
/*

6857

*/