#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,m,i,j,k,x,ans,vis[105];
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof vis);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		ans=0;
		while(k--)
		{
			scanf("%d",&x);
			if(vis[x]) continue;
			if(ans==0) ans=x;
		}
		vis[ans]=1;
		printf("%d\n",ans);
	}
	return 0;
}
