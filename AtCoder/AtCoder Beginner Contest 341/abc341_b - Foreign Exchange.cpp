#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll a[MAX];
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i+1]+=a[i]/x*y;
	}
	printf("%lld\n",a[n]);
	return 0;
}
