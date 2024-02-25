#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],h[MAX];
int main()
{
	int t,n,k,i,j,now,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&h[i]);
		now=0;
		ans=0;
		for(i=1,j=1;i<=n;i++)
		{
			while(j<=n&&(j<=i||h[j-1]%h[j]==0)&&now+a[j]<=k) now+=a[j++];
			ans=max(ans,j-i);
			now-=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
