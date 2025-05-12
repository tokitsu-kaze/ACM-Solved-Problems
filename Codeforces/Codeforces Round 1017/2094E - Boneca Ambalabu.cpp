#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,cnt[32][2];
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(j=0;j<=30;j++) cnt[j][(a[i]>>j)&1]++;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			now=0;
			for(j=0;j<=30;j++)
			{
				now+=(1LL<<j)*cnt[j][!((a[i]>>j)&1)];
			}
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

