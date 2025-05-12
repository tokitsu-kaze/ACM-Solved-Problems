#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,f,mx;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		f=0;
		mx=0;
		for(i=1;i<=n;i++)
		{
			mx=max(mx,a[i]);
			if(a[i]&1)
			{
				ans+=a[i]-1;
				f|=1;
			}
			else
			{
				ans+=a[i];
				f|=2;
			}
		}
		if(f!=3) printf("%d\n",mx);
		else printf("%lld\n",ans+1);
	}
	return 0;
}
