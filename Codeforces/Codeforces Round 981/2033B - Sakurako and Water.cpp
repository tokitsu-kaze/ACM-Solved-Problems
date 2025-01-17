#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int a[505][505];
int main()
{
	int T,n,i,j,k;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]>=0) continue;
				ans+=-a[i][j];
				for(k=1;i+k<=n&&j+k<=n;k++)
				{
					a[i+k][j+k]+=-a[i][j];
				}
				a[i][j]=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
