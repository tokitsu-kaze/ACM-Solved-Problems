#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,mx;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=mx=0;
		for(i=1;i<=n;i+=2)
		{
			if(i>1) mx=max(mx,a[i-1]);
			if(i+1<=n && a[i]>=a[i+1])
			{
				a[i+1]=max(mx,a[i]);
				if(a[i]==a[i+1])
				{
					a[i]--;
					ans++;
				}
			}
			if(i-1>=1 && a[i]>=a[i-1])
			{
				a[i-1]=max(a[i-1],mx);
				ans+=max(0,a[i]-a[i-1]+1);
				mx=max(mx,a[i]);
				a[i]=a[i-1]-1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
