#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[1005];
int main()
{
	int T,n,x,i,j,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		ans=0;
		now=0;
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>=a[i-1]) now++;
			else now=1;
			ans=max(ans,now);
		}
		for(i=1;i<=n;i++)
		{
			a[i]*=x;
			now=0;
			for(j=1;j<=n;j++)
			{
				if(a[j]>=a[j-1]) now++;
				else now=1;
				ans=max(ans,now);
			}
			a[i]/=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
