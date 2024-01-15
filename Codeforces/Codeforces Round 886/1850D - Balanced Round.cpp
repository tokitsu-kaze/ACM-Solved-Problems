#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,k,i,now,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		ans=now=0;
		a[0]=a[1];
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]<=k) now++;
			else now=1;
			ans=max(ans,now);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
