#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,i,j,a[105],b[105],ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		a[0]=b[0]=0;
		for(i=1;i<=n;i++) a[i]+=a[i-1];
		for(i=1;i<=m;i++) b[i]+=b[i-1];
		ans=0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				ans=max(ans,a[i]+b[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

