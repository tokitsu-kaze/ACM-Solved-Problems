#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
ll sum[MAX];
ll cal(int pos,int len)
{
	return 2LL*len*a[pos]
		-(sum[pos+len]-sum[pos]+sum[len]);
}
int main()
{
	int T,n,i,l,r,mid;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		sum[0]=0;
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		ans=sum[n];
		for(i=2;i<n;i++)
		{
			l=0;
			r=min(i,n-i);
			while(l<r)
			{
				mid=(l+r)>>1;
				if(cal(i,mid+1)>cal(i,mid)) l=mid+1;
				else r=mid;
			}
			ans=max(ans,sum[n]+cal(i,l));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

