#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int x[MAX];
int main()
{
	int T,n,a,b,i,pre;
	ll ans,now,sum,ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
			sum+=x[i];
		}
		ans=now=0;
		pre=0;
		for(i=1;i<=n;i++)
		{
			ans+=1LL*b*(x[i]-pre);
			now+=x[i];
			ra=1LL*b*(sum-now-1LL*pre*(n-i));
			rb=1LL*a*(x[i]-pre)+1LL*b*(sum-now-1LL*x[i]*(n-i));
			if(ra>rb)
			{
				ans+=1LL*a*(x[i]-pre);
				pre=x[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

