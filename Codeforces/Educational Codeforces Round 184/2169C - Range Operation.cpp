#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
ll s[MAX];
int main()
{
	int T,n,i;
	ll ans,sum,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		s[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		sum=s[n];
		mn=LLINF;
		ans=sum;
		for(i=1;i<=n;i++)
		{
			mn=min(mn,1LL*i*i-i-s[i-1]);
			ans=max(ans,sum+1LL*i*i+i-s[i]-mn);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
sum+(r-l+1)*(l+r)-s[r]+s[l-1]
sum+(r-l+1)*(l+r)-s[r]+s[l-1]
sum+r*r-l*l+l+r-s[r]+s[l-1]
sum+r*r+r-s[r]-(l*l-l-s[l-1])
*/
