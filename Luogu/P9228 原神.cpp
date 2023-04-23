#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int a[MAX],b[MAX];
int main()
{
	int n,m,i,k;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	ans=0;
	for(i=1;i<=n;i++) ans+=a[i];
	for(i=1;i<=m;i++) ans+=b[i];
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(i=1;i<=min(n,m);i++)
	{
		if(a[i]>=k) ans+=a[i];
		else ans+=k;
	}
	printf("%lld\n",ans);
	return 0;
}
