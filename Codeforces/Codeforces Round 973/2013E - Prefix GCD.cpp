#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,g,nexg,cnt;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		ans=a[1];
		g=a[1];
		cnt=n-1;
		while(cnt>=1)
		{
			nexg=g;
			for(i=1;i<=n;i++) nexg=min(nexg,__gcd(a[i],g));
			if(nexg==g)
			{
				ans+=1LL*cnt*g;
				cnt=0;
			}
			else
			{
				ans+=nexg;
				g=nexg;
				cnt--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
