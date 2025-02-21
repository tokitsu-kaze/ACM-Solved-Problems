#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],sum[MAX];
int main()
{
	int T,n,k,x,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		sum[0]=0;
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		ans=-sum[x]+(sum[n]-sum[x]);
		for(i=1;i<=k;i++)
		{
			ans=max(ans,-(sum[min(n,i+x)]-sum[i])+(sum[n]-sum[min(n,i+x)]));
		}
		printf("%d\n",ans);
	}
	return 0;
}

