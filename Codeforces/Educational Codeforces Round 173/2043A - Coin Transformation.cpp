#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
int main()
{
	int T;
	ll n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ans=1;
		while(n>3)
		{
			n/=4;
			ans*=2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
