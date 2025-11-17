#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=INF;
		for(i=2;i<n;i++)
		{
			if(a[i]>=a[i-1] && a[i]>=a[i+1]) ans=1;
			if(a[i]<=a[i-1] && a[i]<=a[i+1]) ans=1;
		}
		for(i=2;i<=n;i++)
		{
			if(abs(a[i]-a[i-1])<=1) ans=0;
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
