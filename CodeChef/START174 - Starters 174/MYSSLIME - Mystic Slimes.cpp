#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[55],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==2)
		{
			printf("%d\n",abs(a[1]-a[2]));
			continue;
		}
		ans=max(a[1],a[n]);
		a[2]-=a[1];
		a[n-1]-=a[n];
		for(i=2;i<=n-1;i++) ans=max(ans,a[i]);
		printf("%d\n",ans);
	}
	return 0;
}

