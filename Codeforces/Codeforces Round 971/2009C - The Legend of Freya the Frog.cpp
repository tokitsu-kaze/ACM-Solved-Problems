#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=500+10;
int main()
{
	int T,x,y,k;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&k);
		ans=0;
		ans+=(x+k-1)/k;
		ans+=(y+k-1)/k;
		ans+=abs((x+k-1)/k-(y+k-1)/k);
		if((x+k-1)/k>(y+k-1)/k) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}
