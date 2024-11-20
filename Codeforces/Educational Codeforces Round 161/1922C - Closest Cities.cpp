#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
int a[MAX];
ll pre[MAX],suf[MAX];
int main()
{
	int t,n,i,q,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		pre[0]=pre[1]=0;
		for(i=1;i<n;i++)
		{
			if(i>1 && a[i]-a[i-1]<a[i+1]-a[i]) pre[i+1]=pre[i]+a[i+1]-a[i];
			else pre[i+1]=pre[i]+1;
		}
		suf[n+1]=suf[n]=0;
		for(i=n;i>1;i--)
		{
			if(i<n && a[i+1]-a[i]<a[i]-a[i-1]) suf[i-1]=suf[i]+a[i]-a[i-1];
			else suf[i-1]=suf[i]+1;
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&y);
			if(x<y) printf("%lld\n",pre[y]-pre[x]);
			else printf("%d\n",suf[y]-suf[x]);
		}
	}
	return 0;
}
