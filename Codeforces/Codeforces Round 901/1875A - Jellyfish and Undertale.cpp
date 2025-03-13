#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,a,b,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&n);
		ans=b;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans+=min(a-1,x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
