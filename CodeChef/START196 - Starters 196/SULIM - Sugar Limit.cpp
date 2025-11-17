#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[105],b[105],sum[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		memset(sum,0,sizeof sum);
		for(i=1;i<=n;i++) sum[b[i]]+=max(0,a[i]);
		for(i=1;i<=100;i++) sum[i]+=sum[i-1];
		ans=0;
		for(i=1;i<=100;i++) ans=max(ans,sum[i]-i);
		printf("%d\n",ans);
	}
	return 0;
}
