#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5000+10;
int a[MAX],b[MAX];
int main()
{
	int T,ans,i,j,n,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=-1e9;
		for(j=1;j<=n;j++)
		{
			now=a[j]+b[j];
			for(i=1;i<=n;i++)
			{
				if(i==j) continue;
				now+=max(a[i],b[i]);
			}
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}

