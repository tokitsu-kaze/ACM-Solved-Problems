#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,k,i,j,now;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=k;i++) scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		sort(b+1,b+1+k);
		ans=0;
		now=0;
		for(i=1,j=1;i<=n;i++)
		{
			if(now==0 && j<=k) now=b[j++];
			if(now==0)
			{
				ans+=a[i];
				continue;
			}
			now--;
			if(now>0) ans+=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
