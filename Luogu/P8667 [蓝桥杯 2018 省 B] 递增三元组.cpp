#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX],b[MAX],c[MAX];
int main()
{
	int n,i,p1,p2;
	ll ans;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	for(i=0;i<n;i++) scanf("%d",&c[i]);
	sort(a,a+n);
	sort(c,c+n);
	ans=0;
	for(i=0;i<n;i++)
	{
		p1=lower_bound(a,a+n,b[i])-a;
		p2=upper_bound(c,c+n,b[i])-c;
		p2=n-p2;
		ans+=1ll*p1*p2;
	}
	printf("%lld\n",ans);
	return 0;
}
