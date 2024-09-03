#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX],d[MAX];
int main()
{
	int n,i;
	ll ans,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==1) return 0*puts("1");
	for(i=2;i<=n;i++) d[i]=a[i]-a[i-1];
	ans=n;
	cnt=1;
	for(i=3;i<=n;i++)
	{
		if(d[i]==d[i-1]) cnt++;
		else
		{
			ans+=cnt*(cnt+1)/2;
			cnt=1;
		}
	}
	ans+=cnt*(cnt+1)/2;
	printf("%lld\n",ans);
	return 0;
}
