#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int c[MAX],cnt[MAX],sumcnt[MAX];
int main()
{
	int T,n,x,y,i,j,mx,tmp;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&y);
		memset(cnt,0,sizeof cnt);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			cnt[c[i]]++;
			mx=max(mx,c[i]);
		}
		sumcnt[0]=0;
		for(i=1;i<=2*mx;i++) sumcnt[i]=sumcnt[i-1]+cnt[i];
		ans=-LLINF;
		for(x=2;x<=mx+1;x++)
		{
			now=0;
			for(i=x,j=1;i<=mx+x-1;i+=x,j++)
			{
				tmp=sumcnt[i]-sumcnt[i-x];
				now+=1LL*tmp*j;
				now-=1LL*y*max(0,tmp-cnt[j]);
			}
//			printf("%d %lld\n",x,now);
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
