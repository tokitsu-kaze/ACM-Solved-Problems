#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k,i,a[105];
	double ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=0;
	for(i=n-k+1;i<=n;i++) ans=(ans+a[i])/2.0;
	printf("%.5f\n",ans);
	return 0;
}
