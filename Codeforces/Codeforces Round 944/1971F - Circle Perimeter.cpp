#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const long double eps=1e-9;
int main()
{
	int t,r,i;
	ll ans,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&r);
		ans=0;
		for(i=-r;i<=r;i++)
		{
			if(abs(i)==r) now=ll(sqrtl(1LL*(r+1-eps)*(r+1-eps)-1LL*i*i));
			else now=ll(sqrtl(1LL*(r+1-eps)*(r+1-eps)-1LL*i*i))-ll(sqrtl(1LL*(r-eps)*(r-eps)-1LL*i*i));
			ans+=now;
		}
		printf("%lld\n",2*ans+2);
	}
	return 0;
}
