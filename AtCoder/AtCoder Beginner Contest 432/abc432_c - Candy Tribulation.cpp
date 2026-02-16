#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int n,x,y,i;
	ll ans,tot,tmp;
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=a[1];
	tot=1LL*a[1]*y;
	for(i=2;i<=n;i++)
	{
		if((1LL*a[i]*y-tot)%(y-x))
		{
			ans=-1;
			break;
		}
		tmp=(1LL*a[i]*y-tot)/(y-x);
		if(tmp>a[i])
		{
			ans=-1;
			break;
		}
		ans+=a[i]-tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
