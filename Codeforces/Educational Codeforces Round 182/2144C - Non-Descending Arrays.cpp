#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
const int mod=998244353;
int a[MAX],b[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=2;
		for(i=2;i<=n;i++)
		{
			if(min(a[i],b[i])>=max(a[i-1],b[i-1])) ans=ans*2%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
