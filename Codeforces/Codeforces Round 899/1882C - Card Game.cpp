#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX];
int main()
{
	int T,n,i,j;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(j=1;j<=min(n,2);j++)
		{
			now=0;
			for(i=1;i<j;i+=2) now+=max(a[i],0);
			if(j&1) now+=a[j];
			for(i=j+1;i<=n;i++) now+=max(a[i],0);
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
