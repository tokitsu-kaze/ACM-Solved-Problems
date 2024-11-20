#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
int cnt[MAX];
int main()
{
	int t,n,i,x;
	ll ans,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		ans=now=0;
		for(i=0;i<=n;i++)
		{
			if(cnt[i]>=2)
			{
				ans+=1LL*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
				ans+=1LL*cnt[i]*(cnt[i]-1)*now/2;
			}
			now+=cnt[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
