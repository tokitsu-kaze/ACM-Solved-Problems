#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll a[MAX];
int main()
{
	int T,n,i,j;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n%2==0)
		{
			ans=0;
			for(i=2;i<=n;i+=2) ans=max(ans,a[i]-a[i-1]);
			printf("%lld\n",ans);
			continue;
		}
		ans=1e18;
		for(j=1;j<=n;j++)
		{
			vector<int> pos;
			for(i=1;i<=n;i++)
			{
				if(i==j) continue;
				pos.push_back(i);
			}
			now=0;
			for(i=1;i<pos.size();i+=2)
			{
				now=max(now,a[pos[i]]-a[pos[i-1]]);
			}
			ans=min(ans,now);
		}
		ans=max(ans,1LL);
		printf("%lld\n",ans);
	}
	return 0;
}
