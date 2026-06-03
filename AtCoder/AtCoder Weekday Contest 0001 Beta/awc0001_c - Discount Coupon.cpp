#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int d[MAX];
int main()
{
	int n,k,i;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	sort(d+1,d+1+n);
	ans=0;
	for(i=1;i<=n-k;i++) ans+=d[i];
	printf("%lld\n",ans);
	return 0;
}
