#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
int a[MAX];
int main()
{
	int T,n,i,l,r;
	ll x,y,ans,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%lld",&n,&x,&y);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+1+n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			r=upper_bound(a+1,a+1+n,sum-a[i]-x)-a-1;
			l=lower_bound(a+1,a+1+n,sum-a[i]-y)-a;
//			printf("%d %d %d\n",i,l,r);
			ans+=max(0,r-max(i+1,l)+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
