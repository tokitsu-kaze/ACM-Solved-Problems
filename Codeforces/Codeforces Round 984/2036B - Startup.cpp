#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX],sum[MAX];
int main()
{
	int T,n,k,i,a,b;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++) sum[i]=0;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&a,&b);
			sum[a]+=b;
		}
		sort(sum+1,sum+1+k);
		reverse(sum+1,sum+1+k);
		ans=0;
		for(i=1;i<=min(n,k);i++) ans+=sum[i];
		printf("%lld\n",ans);
	}
	return 0;
}
