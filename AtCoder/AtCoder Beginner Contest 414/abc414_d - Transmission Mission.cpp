#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
ll x[MAX],d[MAX];
int main()
{
	int n,m,i;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&x[i]);
	sort(x+1,x+1+n);
	for(i=1;i<n;i++) d[i]=x[i+1]-x[i];
	sort(d+1,d+n);
	ans=0;
	for(i=1;i<=n-m;i++) ans+=d[i];
	printf("%lld\n",ans);
	return 0;
}
