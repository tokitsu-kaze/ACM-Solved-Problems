#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	ll ans,pre,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n<=2)
		{
			printf("%d\n",n*(n-1)/2);
			continue;
		}
		ans=0;
		now=2;
		pre=0;
		for(i=3;i<=n;i++)
		{
			if((a[i-1]-a[i-2])*(a[i]-a[i-1])<0)
			{
				if(pre==0) ans+=now*(now-1)/2;
				else ans+=(now-1)*(now-2)/2;
				pre=now;
				now=2;
			}
			else now++;
			ans+=pre;
		}
		if(pre==0) ans+=now*(now-1)/2;
		else ans+=(now-1)*(now-2)/2;
		printf("%lld\n",ans);
	}
	return 0;
}

