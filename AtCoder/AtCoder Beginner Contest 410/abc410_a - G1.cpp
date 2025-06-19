#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int n,i,a[105],k,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&k);
	ans=0;
	for(i=1;i<=n;i++) ans+=(a[i]>=k);
	printf("%d\n",ans);
	return 0;
}
