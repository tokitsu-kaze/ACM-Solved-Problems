#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int c[MAX],a[MAX],b[MAX];
int main()
{
	int T,n,i;
	ll ans,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++)
		{
			if(a[i]>b[i]) swap(a[i],b[i]);
		}
		ans=sum=0;
		a[n+1]=b[n+1]=0;
		for(i=n;i>1;i--)
		{
			if(a[i+1]==b[i+1]) sum=c[i]-1;
			else sum+=(c[i]-b[i+1])+(a[i+1]-1);
			sum=max(sum,c[i]-1LL);
			sum+=2;
			ans=max(ans,sum+b[i]-a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

