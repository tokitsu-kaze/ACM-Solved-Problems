#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,ans;
	ll now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		now=1;
		while(k!=1 && now*k<=n) now*=k;
		ans=0;
		while(now>1)
		{
			ans+=n/now;
			n%=now;
			now/=k;
		}
		ans+=n;
		printf("%d\n",ans);
	}
	return 0;
}
