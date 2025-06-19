#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,cnt[2],sum;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x&1]++;
		}
		sum=(cnt[1]&1);
		ans=0;
		if(sum==0)
		{
			ans+=1LL*cnt[0]*(cnt[0]-1)/2;
			ans+=1LL*cnt[1]*(cnt[1]-1)/2;
			ans+=1LL*cnt[0]*cnt[1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
