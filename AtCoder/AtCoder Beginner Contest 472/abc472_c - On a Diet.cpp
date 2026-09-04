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
	int n,m,i,l;
	ll k;
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		l=max(1,i-m+1);
		if(sum[i]-sum[l-1]>k)
		{
			sum[i]-=a[i];
			puts("No");
		}
		else puts("Yes");
	}
	return 0;
}
