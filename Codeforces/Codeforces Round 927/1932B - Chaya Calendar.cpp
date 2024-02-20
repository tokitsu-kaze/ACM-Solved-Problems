#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,n,i;
	ll x,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			ans=(ans/x+1)*x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
