#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX];
int main()
{
	int t,n,k,i,j,tmp;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		ans=0;
		for(i=1;i<n;i+=2)
		{
			tmp=min(k,a[i]-a[i+1]);
			ans+=max(0,a[i]-(a[i+1]+tmp));
			k-=tmp;
		}
		if(n&1) ans+=a[n];
		printf("%lld\n",ans);
	}
	return 0;
}

