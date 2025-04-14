#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
int main()
{
	int T,n,m,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		for(i=n-1;i;i--) cnt[i]+=cnt[i+1];
		ans=0;
		for(i=1;i<n;i++)
		{
			x=min(cnt[i],cnt[n-i]);
			ans+=1LL*x*(x-1);
			if(i<n-i) ans+=1LL*(cnt[i]-cnt[n-i])*cnt[n-i];
			else ans+=1LL*(cnt[n-i]-cnt[i])*cnt[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

