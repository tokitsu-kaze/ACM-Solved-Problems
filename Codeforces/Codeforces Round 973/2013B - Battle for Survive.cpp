#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
ll sum[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		printf("%lld\n",sum[n]-2*a[n-1]);
	}
	return 0;
}
