#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,ans,i;
	scanf("%lld%lld",&a,&b);
	ans=__builtin_popcountll(a);
	for(i=0;i<63;i++)
	{
		if(a&(1LL<<i)) continue;
		if((a|(1LL<<i))<=b)
		{
			a|=(1LL<<i);
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
