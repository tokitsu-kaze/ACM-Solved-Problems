#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,j,a[105],ans,vis[105],ok;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=n;
	for(i=n;i;i--)
	{
		memset(vis,0,sizeof vis);
		for(j=1;j<=i;j++) vis[a[j]]=1;
		ok=0;
		for(j=1;j<=m;j++)
		{
			if(!vis[j]) ok=1;
		}
		if(ok)
		{
			ans=n-i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
