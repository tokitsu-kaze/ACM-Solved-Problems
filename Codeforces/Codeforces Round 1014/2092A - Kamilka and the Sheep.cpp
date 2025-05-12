#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,n,i,j,a[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				ans=max(ans,abs(a[i]-a[j]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
