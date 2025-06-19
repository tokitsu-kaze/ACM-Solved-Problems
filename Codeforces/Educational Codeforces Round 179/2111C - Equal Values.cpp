#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int T,n,i,l;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=LLINF;
		l=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]!=a[l])
			{
				ans=min(ans,1LL*a[l]*((l-1)+(n-(i-1))));
				l=i;
			}
		}
		ans=min(ans,1LL*a[n]*(l-1));
		printf("%lld\n",ans);
	}
	return 0;
}
