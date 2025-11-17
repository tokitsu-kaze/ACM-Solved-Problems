#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int T,n,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans*=x;
		}
		ans+=n-1;
		printf("%lld\n",2022*ans);
	}
	return 0;
}
