#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,j,ans,a[11],sum;
	scanf("%d",&T);
	while(T--)
	{
		n=5;
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum>=n*7)
		{
			puts("0");
			continue;
		}
		sort(a+1,a+1+n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			sum-=a[i];
			a[i]=10;
			sum+=a[i];
			ans+=100;
			if(sum>=n*7) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
