#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[MAX],b[MAX],c[MAX],d[MAX];
int main()
{
	int i,n,x,y,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	scanf("%d%d",&x,&y);
	ans=-1;
	for(i=n;i;i--)
	{
		if(x>=a[i] && x<=a[i]+c[i] && y>=b[i] &&y<=b[i]+d[i])
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
