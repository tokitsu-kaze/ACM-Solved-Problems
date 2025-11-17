#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int main()
{
	int T,n,i;
	ll ans,sd,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		sd=1;
		x=0;
		while(n)
		{
			ans+=(n%3)*((sd*3)+x*sd/3);
			n/=3;
			sd*=3;
			x++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

