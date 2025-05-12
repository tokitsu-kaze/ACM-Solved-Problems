#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
int main()
{
	int n,i;
	ll sum,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=sum=0;
	for(i=1;i<=n;i++)
	{
		ans+=1LL*a[i]*sum;
		sum+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
