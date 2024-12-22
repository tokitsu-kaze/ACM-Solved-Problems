#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll x[MAX],h[MAX];
int main()
{
	int n,i;
	double ans;
	scanf("%d",&n);
	ans=-1e18;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&h[i]);
		if(i>1) ans=max(ans,1.0*(x[i]*h[i-1]-h[i]*x[i-1])/(x[i]-x[i-1]));
	}
	if(ans<0) puts("-1");
	else printf("%.10f\n",ans);
	return 0;
}
