#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,tmp;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<n;i+=2)
		{
			tmp=max(0,a[i]-a[i+1]);
			ans+=tmp;
			a[i]-=tmp;
		}
		for(i=3;i<=n;i+=2)
		{
			tmp=max(0,a[i]+a[i-2]-a[i-1]);
			ans+=tmp;
			a[i]-=tmp;
		}
//		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		printf("%lld\n",ans);
	}
	return 0;
}
