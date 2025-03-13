#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i*2<=n;i++) ans+=1LL*i*(n-i)+1;
		printf("%lld\n",ans);
	}
	return 0;
}
