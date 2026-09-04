#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,a[105],i,pre,suf,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	suf=0;
	for(i=1;i<=n;i++) suf+=a[i];
	ans=INF;
	pre=0;
	for(i=1;i<n;i++)
	{
		pre+=a[i];
		suf-=a[i];
		ans=min(ans,abs(pre-suf));
	}
	printf("%d\n",ans);
	return 0;
}
