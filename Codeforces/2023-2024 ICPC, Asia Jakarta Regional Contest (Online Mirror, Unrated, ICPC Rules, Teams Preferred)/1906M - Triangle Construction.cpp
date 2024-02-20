#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,x,mx;
	ll sum;
	scanf("%d",&n);
	mx=0;
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mx=max(mx,x);
		sum+=x;
	}
	if((sum-mx)*2<mx) printf("%lld\n",sum-mx);
	else printf("%lld\n",sum/3);
	return 0;
}
